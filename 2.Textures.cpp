#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "Shader.h"
#include "stb_image.h"
unsigned int shaderProgram;
unsigned int VAO;
unsigned int texture;
unsigned int texture1;
float vertices[] = {
	//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // ����
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // ����
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // ����
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // ����
};

unsigned int indices[] = {
	// ע��������0��ʼ! 
	// ����������(0,1,2,3)���Ƕ�������vertices���±꣬
	// �����������±��������ϳɾ���

	0, 1, 3, // ��һ��������
	1, 2, 3  // �ڶ���������
};
GLFWwindow* window;
float lastX = 400, lastY = 300;
float yaw = 0, pitch = 0; //ƫ����, ������
bool firstMouse = true;
//���ڳߴ�ı�ص�
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

#pragma region ����
void processInput(GLFWwindow* window) {
	//û�а��»᷵��GLFW_RELEASE
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
#pragma endregion

int main()
{
	//glm::mat4 trans = glm::mat4(1.0f);
	glfwInit();
	//����OpenGL 3.3
	//���汾��(Major)��Ϊ3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//�ΰ汾��(Minor)����Ϊ3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//����glfwCreateWindow(width,hight,title,ignore,ignore)
	window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

#pragma region glad��ʼ��
	//GLFW�ṩglfwGetProcAddress��Ϊ��������ϵͳ��ص�OpenGL����ָ���ַ�ĺ���
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to init GLAD" << std::endl;
		return -1;
	}
#pragma endregion

#pragma region �ӿ�
	//glViewport(���ƴ������½�X,���ƴ������½�Y,������Ⱦ���ڵĿ��(���أ�,������Ⱦ���ڵĿ�Ⱥ͸߶ȣ����أ�)
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
#pragma endregion
#pragma region ����ͼ�γ�ʼ��
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	//����һ�����л���ID��VBO����
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	Shader ourShdaer = Shader("C:/Users/Yalla/Desktop/Opengl/Shader/2.textureshader.vs", "C:/Users/Yalla/Desktop/Opengl/Shader/2.textureshader.fs");

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
#pragma endregion

#pragma region �߿�ģʽ(Wireframe Mode)
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#pragma endregion

#pragma region ����
	//����
	int width, height, nrChannels;
	unsigned char* data = stbi_load("C:/Users/Yalla/Desktop/Opengl/Resources/container.jpg", &width, &height, &nrChannels, 0);

	//��������
	
	//glGenTextures����������Ҫ�������������������Ȼ������Ǵ����ڵڶ���������unsigned int�����У����ǵ�������ֻ�ǵ�����һ��unsigned int��
	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0);
	//��
	glBindTexture(GL_TEXTURE_2D, texture);

	// Ϊ��ǰ�󶨵�����������û��ơ����˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data)
	{
		//����
		//������glTexImage2Dʱ����ǰ�󶨵��������ͻᱻ����������ͼ��
		//��һ������ָ��������Ŀ��(Target)������ΪGL_TEXTURE_2D��ζ�Ż������뵱ǰ�󶨵����������ͬһ��Ŀ���ϵ������κΰ󶨵�GL_TEXTURE_1D��GL_TEXTURE_3D���������ܵ�Ӱ�죩��
		//�ڶ�������Ϊ����ָ���༶��Զ����ļ��������ϣ�������ֶ�����ÿ���༶��Զ����ļ���Ļ�������������0��Ҳ���ǻ�������
		//��������������OpenGL����ϣ����������Ϊ���ָ�ʽ�����ǵ�ͼ��ֻ��RGBֵ���������Ҳ��������ΪRGBֵ��
		//���ĸ��͵���������������յ�����Ŀ�Ⱥ͸߶ȡ�����֮ǰ����ͼ���ʱ�򴢴������ǣ���������ʹ�ö�Ӧ�ı�����
		//�¸�����Ӧ�����Ǳ���Ϊ0����ʷ���������⣩��
		//���ߵڰ˸�����������Դͼ�ĸ�ʽ���������͡�����ʹ��RGBֵ�������ͼ�񣬲������Ǵ���Ϊchar(byte)���飬���ǽ��ᴫ���Ӧֵ��
		//�ھŸ�������������ͼ�����ݡ�
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		//����mipmap
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else 
	{
		std::cout << "Failed to laod texture" << std::endl;
	}

	//�ͷ�����
	stbi_image_free(data);


	//���صڶ���ͼ
	 
	//�ܹ���ͼ�����ʱ�������Ƿ�תy�ᣬֻ��Ҫ�ڼ����κ�ͼ��ǰ����������伴�ɣ�
	stbi_set_flip_vertically_on_load(true); 
	unsigned char* data1 = stbi_load("C:/Users/Yalla/Desktop/Opengl/Resources/awesomeface.png", &width, &height, &nrChannels, 0);

	//��������
	
	//glGenTextures����������Ҫ�������������������Ȼ������Ǵ����ڵڶ���������unsigned int�����У����ǵ�������ֻ�ǵ�����һ��unsigned int��
	glGenTextures(1, &texture1);

	glActiveTexture(GL_TEXTURE1);
	//��
	glBindTexture(GL_TEXTURE_2D, texture1);

	// Ϊ��ǰ�󶨵�����������û��ơ����˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data1)
	{
		
		//����
		//������glTexImage2Dʱ����ǰ�󶨵��������ͻᱻ����������ͼ��
		//��һ������ָ��������Ŀ��(Target)������ΪGL_TEXTURE_2D��ζ�Ż������뵱ǰ�󶨵����������ͬһ��Ŀ���ϵ������κΰ󶨵�GL_TEXTURE_1D��GL_TEXTURE_3D���������ܵ�Ӱ�죩��
		//�ڶ�������Ϊ����ָ���༶��Զ����ļ��������ϣ�������ֶ�����ÿ���༶��Զ����ļ���Ļ�������������0��Ҳ���ǻ�������
		//��������������OpenGL����ϣ����������Ϊ���ָ�ʽ�����ǵ�ͼ��ֻ��RGBֵ���������Ҳ��������ΪRGBֵ��
		//���ĸ��͵���������������յ�����Ŀ�Ⱥ͸߶ȡ�����֮ǰ����ͼ���ʱ�򴢴������ǣ���������ʹ�ö�Ӧ�ı�����
		//�¸�����Ӧ�����Ǳ���Ϊ0����ʷ���������⣩��
		//���ߵڰ˸�����������Դͼ�ĸ�ʽ���������͡�����ʹ��RGBֵ�������ͼ�񣬲������Ǵ���Ϊchar(byte)���飬���ǽ��ᴫ���Ӧֵ��
		//�ھŸ�������������ͼ�����ݡ�
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data1);

		//����mipmap
		glGenerateMipmap(GL_TEXTURE_2D);
	
	}
	else
	{
		std::cout << "Failed to laod texture" << std::endl;
	}

	//�ͷ�����
	stbi_image_free(data1);
	// ��Ҫ����������uniform����֮ǰ������ɫ������
	ourShdaer.Use();
	//����ÿ���������ķ�ʽ����OpenGLÿ����ɫ�������������ĸ�����Ԫ,ֻ��Ҫ����һ��
	glUniform1i(glGetUniformLocation(ourShdaer.ID, "texture1"), 1);
	ourShdaer.SetInt("texture2", 0);

#pragma endregion


	//glfwWindowShouldClose����������ÿ��ѭ���Ŀ�ʼǰ���һ��GLFW�Ƿ�Ҫ���˳���
	//����ǵĻ����ú�������true����Ⱦѭ����ֹͣ���У�֮�����ǾͿ��Թر�Ӧ�ó���
	while (!glfwWindowShouldClose(window))
	{
		//ÿ֡��ⰴ������
		processInput(window);

#pragma region ��Ⱦѭ��(Render Loop)
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//����ͨ������glClear�����������Ļ����ɫ���壬������һ������λ(Buffer Bit)��ָ��Ҫ��յĻ��壬
		//���ܵĻ���λ��GL_COLOR_BUFFER_BIT��GL_DEPTH_BUFFER_BIT��GL_STENCIL_BUFFER_BIT��
		glClear(GL_COLOR_BUFFER_BIT);

		
#pragma region ������ɫ��shader���в���
		float time = glfwGetTime();
		float g = sin(time) * 0.5f + 0.5f;
		ourShdaer.SetFloat("ourColor", g);
		//int pos = glGetUniformLocation(shaderProgram, "ourColor");
		//glUniform4f(pos, 0.0f, g, 0.0f, 1.0f);
#pragma endregion
		//������
		glBindTexture(GL_TEXTURE_2D, texture);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glActiveTexture(GL_TEXTURE1);

		//����������
		//glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		ourShdaer.Use();
#pragma region EBO
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glBindVertexArray(0);
#pragma endregion
#pragma endregion


		//glfwSwapBuffers�����ύ����ɫ���壨����һ��������GLFW����ÿһ��������ɫֵ�Ĵ󻺳壩��������һ�����б��������ƣ����ҽ�����Ϊ�����ʾ����Ļ�ϡ�
		glfwSwapBuffers(window);

		//glfwPollEvents���������û�д���ʲô�¼�������������롢����ƶ��ȣ������´���״̬�������ö�Ӧ�Ļص�����������ͨ���ص������ֶ����ã���
		glfwPollEvents();

	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	//��Ⱦѭ����������Ҫ��ȷ�ͷ�/ɾ��֮ǰ�ķ����������Դ
	glfwTerminate();
	return 0;
}

void Test() {
	glm::mat4 trans = glm::mat4(1.0f);
	//���ӿռ�Ĵ�ƽ��ͷ��
	// ����1:������fov��ֵ������ʾ������Ұ(Field of View)�����������˹۲�ռ�Ĵ�С�������Ҫһ����ʵ�Ĺ۲�Ч��������ֵͨ������Ϊ45.0f��
	// ����Ҫһ������սʿ(DOOM,�����ϵ�е�һ�˳������Ϸ)���Ľ������Խ�������һ�������ֵ��
	// ������:�����˿�߱ȣ����ӿڵĿ���Ը����á�
	// ������:������ƽ��ͷ��Ľ�ƽ��
	// ������:������ƽ��ͷ���Զƽ�档
	// ����ͨ�����ý�����Ϊ0.1f����Զ������Ϊ100.0f�������ڽ�ƽ���Զƽ�����Ҵ���ƽ��ͷ���ڵĶ��㶼�ᱻ��Ⱦ��
	//glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	//ע:�����͸�Ӿ���� near ֵ����̫��ʱ����10.0f����OpenGL�Ὣ��������������꣨��0.0f��10.0f֮�䣩���ü�����
	//��ᵼ��һ��������Ϸ�к���Ϥ���Ӿ�Ч������̫������һ�������ʱ��������߻�ֱ�Ӵ���ȥ��
}

void BuildCamera() {
	//������������ϵ

	//1���λ��
	//
	//��z���Ǵ���Ļָ����ģ��������ϣ�����������ƶ������Ǿ�����z����������ƶ���
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);

	//2�������
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);//��������ԭ��
	glm::vec3 cameraDirection = glm::normalize(cameraTarget - cameraPos);//���ָ������ԭ��

	//3����ռ����� x������
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	//Ϊ��ȡ������������Ҫ��ʹ��һ��С���ɣ��ȶ���һ��������(Up Vector)��
	//���������������͵ڶ����õ��ķ����������в�ˡ�����������˵Ľ����ͬʱ��ֱ����������������ǻ�õ�ָ��x����������Ǹ�����
	//��������ǽ�������������˵�˳��ͻ�õ��෴��ָ��x�Ḻ�����������
	glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	//4���� ��y������
	glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

	//ע:����ķ��ʩ����������(Gram-Schmidt Process)��ʹ����Щ������������ǾͿ��Դ���һ��LookAt�����ˣ����ڴ����������ʱ��ǳ����á�
	//����ά�ռ��У������ʩ�����������ļ���ʵ�֣���������ѧ�ϵȼ�

	glm::mat4 view = glm::lookAt(cameraPos, cameraTarget, up);

}
void mouse_callback(GLFWwindow* window,double xpos,double ypos ) {

	if (firstMouse) // ���bool������ʼʱ���趨Ϊtrue��
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // ע���������෴�ģ���Ϊy�����Ǵӵײ����������������
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.05f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	front.y = sin(glm::radians(pitch));
	front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
	glm::vec3 cameraFront = glm::normalize(front);
}

void MouseInput() {
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback);
}