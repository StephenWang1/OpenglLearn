//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include "Shader.h"
//
////���ڳߴ�ı�ص�
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//#pragma region ����
//void processInput(GLFWwindow* window) {
//	//û�а��»᷵��GLFW_RELEASE
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, true);
//	}
//}
//#pragma endregion
//
//#pragma region �����λ���
////�����������Vertex Array Object��VAO
////���㻺�����Vertex Buffer Object��VBO
////Ԫ�ػ������Element Buffer Object��EBO �� ����������� Index Buffer Object��IBO
//
//#pragma region ������ɫ��
////ÿ����ɫ������ʼ��һ���汾������OpenGL 3.3�Լ��͸��߰汾�У�GLSL�汾�ź�OpenGL�İ汾��ƥ��ģ�����˵GLSL 420�汾��Ӧ��OpenGL 4.2����
////����ͬ����ȷ��ʾ���ǻ�ʹ�ú���ģʽ��
////#version 330 core
//// layout (location = 0)�趨�����������λ��ֵ(Location)
////ʹ��in�ؼ��֣��ڶ�����ɫ�����������е����붥������(Input Vertex Attribute)��
////layout(location = 0) in vec3 aPos;
////void main()
////{
//   // gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
////}
//#pragma endregion
//#pragma region ƬԪ��ɫ��
////#version 330 core
//// out �����������
////out vec4 FragColor;
//
////void main()
////{
//	//FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
////}
//#pragma endregion
//
//#pragma region ������ɫ��
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec3 aColor;\n"
//"out vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos, 1.0);\n"
//	"ourColor = aColor;\n"
//"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"in vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"FragColor = vec4(ourColor,1.0);\n"
//"}\0";
//#pragma endregion
//
//
//
//float vertices[] = {
//	// λ��              // ��ɫ
//	0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // ����
//   -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // ����
//	0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // ����
//};
//
//unsigned int indices[] = {
//	// ע��������0��ʼ! 
//	// ����������(0,1,2,3)���Ƕ�������vertices���±꣬
//	// �����������±��������ϳɾ���
//
//	0, 1, 3, // ��һ��������
//	1, 2, 3  // �ڶ���������
//};
//unsigned int shaderProgram;
//unsigned int VAO;
//
//void drawTriangleInit() {
//
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	unsigned int VBO;
//	//����һ�����л���ID��VBO����
//	glGenBuffers(1, &VBO);
//	//���㻺�����Ļ���������GL_ARRAY_BUFFER, OpenGL�кܶ໺���������.
//	// OpenGL����ͬʱ�󶨶�����壬ֻҪ�����ǲ�ͬ�Ļ������͡�ʹ��glBindBuffer�������´����Ļ���󶨵�GL_ARRAY_BUFFERĿ���ϣ�
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//glBufferData��һ��ר���������û���������ݸ��Ƶ���ǰ�󶨻���ĺ�����
//	//��һ��������Ŀ�껺������ͣ����㻺�����ǰ�󶨵�GL_ARRAY_BUFFERĿ���ϡ�
//	//�ڶ�������ָ���������ݵĴ�С(���ֽ�Ϊ��λ)����һ���򵥵�sizeof������������ݴ�С���С�
//	//����������������ϣ�����͵�ʵ�����ݡ�
//	/*���ĸ�����ָ��������ϣ���Կ���ι�����������ݡ�����������ʽ��
//		GL_STATIC_DRAW �����ݲ���򼸺�����ı䡣
//		GL_DYNAMIC_DRAW�����ݻᱻ�ı�ܶࡣ
//		GL_STREAM_DRAW ������ÿ�λ���ʱ����ı䡣
//	�����ε�λ�����ݲ���ı䣬ÿ����Ⱦ����ʱ������ԭ������������ʹ�����������GL_STATIC_DRAW��
//	���������˵һ�������е����ݽ�Ƶ�����ı䣬��ôʹ�õ����;���GL_DYNAMIC_DRAW��GL_STREAM_DRAW����������ȷ���Կ������ݷ����ܹ�����д����ڴ沿�֡�*/
//	//���������ݴ������Կ����ڴ��У���VBO������㻺��������
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//#pragma region EBO
//	/*unsigned int EBO;
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/
//#pragma endregion
//	Shader ourShdaer = Shader("C:/Users/Yalla/Desktop/Opengl/Shader/3.3.shader.vs", "C:/Users/Yalla/Desktop/Opengl/Shader/3.3.shader.fs");
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
////#pragma region ������ɫ��
////#pragma region ������ɫ��
////	unsigned int vertexShader;
////	vertexShader = glCreateShader(GL_VERTEX_SHADER);
////	//glShaderSource������Ҫ�������ɫ��������Ϊ��һ��������
////	//�ڶ�����ָ���˴��ݵ�Դ���ַ�������������ֻ��һ����
////	//�����������Ƕ�����ɫ��������Դ�룬
////	//���ĸ���������������ΪNULL��
////	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
////	glCompileShader(vertexShader);
////	int success;
////	char infoLog[512];
////	//����ڵ���glCompileShader������Ƿ�ɹ�
////	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
////	if (!success)
////	{
////		//glGetShaderInfoLog��ȡ������Ϣ
////		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
////		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
////	}
////#pragma endregion
////#pragma region ƬԪ��ɫ��
////	unsigned int fragmentShader;
////	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
////	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
////	glCompileShader(fragmentShader);
////	//����ڵ���glCompileShader������Ƿ�ɹ�
////	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
////	if (!success)
////	{
////		//glGetShaderInfoLog��ȡ������Ϣ
////		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
////		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
////	}
////
////#pragma endregion
////
////#pragma region ��ɫ������(Shader Program)
////	//��ɫ���������(Shader Program Object)�Ƕ����ɫ���ϲ�֮������������ɵİ汾
////	
////	shaderProgram = glCreateProgram();
////	glAttachShader(shaderProgram, vertexShader);
////	glAttachShader(shaderProgram, fragmentShader);
////	glLinkProgram(shaderProgram);
////
////	//����ڵ���glCompileShader������Ƿ�ɹ�
////	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
////	if (!success)
////	{
////		//glGetShaderInfoLog��ȡ������Ϣ
////		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
////		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
////	}
////	//glUseProgram ����������
////	glUseProgram(shaderProgram);
////	glDeleteShader(vertexShader);
////	glDeleteShader(fragmentShader);
////	//�Ѿ������붥�����ݷ��͸���GPU����ָʾ��GPU����ڶ����Ƭ����ɫ���д�����
////#pragma endregion
//	//Shader ourShdaer("3.3.shader.vs", "3.3.shader.fs");
//	glBindVertexArray(VAO);
//	glDrawArrays(GL_TRIANGLES, 0, 3);
//
//#pragma endregion
//#pragma region ���Ӷ�������
////��һ������ָ������Ҫ���õĶ������ԡ����ǵ������ڶ�����ɫ����ʹ��layout(location = 0)������position�������Ե�λ��ֵ(Location)��
//// �����԰Ѷ������Ե�λ��ֵ����Ϊ0����Ϊ����ϣ�������ݴ��ݵ���һ�����������У������������Ǵ���0��
////�ڶ�������ָ���������ԵĴ�С������������һ��vec3������3��ֵ��ɣ����Դ�С��3��
////����������ָ�����ݵ����ͣ�������GL_FLOAT(GLSL��vec * �����ɸ�����ֵ��ɵ�)��
////���ĸ��������������Ƿ�ϣ�����ݱ���׼��(Normalize)�������������ΪGL_TRUE���������ݶ��ᱻӳ�䵽0�������з�����signed������ - 1����1֮�䡣���ǰ�������ΪGL_FALSE��
////�����������������(Stride)�������������������Ķ���������֮��ļ���������¸���λ��������3��float֮�����ǰѲ�������Ϊ3 * sizeof(float)��
//// Ҫע�������������֪����������ǽ������еģ���������������֮��û�п�϶������Ҳ��������Ϊ0����OpenGL�������岽���Ƕ��٣�ֻ�е���ֵ�ǽ�������ʱ�ſ��ã���
//// һ�������и���Ķ������ԣ����Ǿͱ����С�ĵض���ÿ����������֮��ļ����
//// �����ں���ῴ����������ӣ���ע: �����������˼��˵���Ǵ�������Եڶ��γ��ֵĵط�����������0λ��֮���ж����ֽڣ���
////������������������void * ��������Ҫ���ǽ��������ֵ�ǿ������ת��������ʾλ�������ڻ�������ʼλ�õ�ƫ����(Offset)������λ������������Ŀ�ͷ������������0��
////���ǻ��ں�����ϸ�������������
////glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
////glEnableVertexAttribArray(0);
////ע:ÿ���������Դ�һ��VBO������ڴ��л���������ݣ��������Ǵ��ĸ�VBO�������п����ж��VBO����ȡ����ͨ���ڵ���glVertexAttribPointerʱ�󶨵�GL_ARRAY_BUFFER��VBO�����ġ�
////�����ڵ���glVertexAttribPointer֮ǰ�󶨵�����ǰ�����VBO���󣬶�������0���ڻ����ӵ����Ķ������ݡ�
//
////// 0. ���ƶ������鵽�����й�OpenGLʹ��
////glBindBuffer(GL_ARRAY_BUFFER, VBO);
////glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
////// 1. ���ö�������ָ��
////glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
////glEnableVertexAttribArray(0);
////// 2. ��������Ⱦһ������ʱҪʹ����ɫ������
////glUseProgram(shaderProgram);
////// 3. ��������
////someOpenGLFunctionThatDrawsOurTriangle();
//#pragma endregion
//
//#pragma region �����������(Vertex Array Object, VAO)
//	//ע:OpenGL�ĺ���ģʽҪ������ʹ��VAO��������֪������δ������ǵĶ������롣������ǰ�VAOʧ�ܣ�OpenGL��ܾ������κζ�����
//	//unsigned int VAO;
//	//glGenVertexArrays(1, &VAO);
//
//	//// ..:: ��ʼ�����루ֻ����һ�� (�����������Ƶ���ı�)�� :: ..
//	//// 1. ��VAO
//	//glBindVertexArray(VAO);
//	//// 2. �Ѷ������鸴�Ƶ������й�OpenGLʹ��
//	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	//// 3. ���ö�������ָ��
//	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	//glEnableVertexAttribArray(0);
//
//	//[...]
//
//	//// ..:: ���ƴ��루��Ⱦѭ���У� :: ..
//	//// 4. ��������
//	//glUseProgram(shaderProgram);
//	//glBindVertexArray(VAO);
//	//someOpenGLFunctionThatDrawsOurTriangle();
//#pragma endregion
//
//#pragma region Ԫ�ػ������(Element Buffer Object��EBO)���������������(Index Buffer Object��IBO)
//	//EBO��һ��������������һ�����㻺��������һ�������洢 OpenGL ��������Ҫ������Щ�����������
//	//������ν����������(Indexed Drawing)������������Ľ������
//	//unsigned int EBO;
//	//glGenBuffers(1, &EBO);
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	// ��һ������ָ���˻��Ƶ�ģʽ�������glDrawArrays��һ����
//	// �ڶ��������Ǵ�����ƶ���ĸ�����������6��Ҳ����˵����һ����Ҫ����6�����㡣
//	// ���������������������ͣ�������GL_UNSIGNED_INT��
//	// ���ĸ����������ָ��EBO�е�ƫ���������ߴ���һ���������飬�������ǵ��㲻��ʹ��������������ʱ�򣩣��������ǻ���������д0��
//	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//	//�ڰ�VAOʱ���󶨵����һ��Ԫ�ػ���������洢ΪVAO��Ԫ�ػ���������Ȼ�󣬰󶨵�VAOҲ���Զ��󶨸�EBO��
//	
//	//ע:��Ŀ����GL_ELEMENT_ARRAY_BUFFER��ʱ��VAO�ᴢ��glBindBuffer�ĺ������á�
//	//��Ҳ��ζ����Ҳ�ᴢ������ã�����ȷ����û���ڽ��VAO֮ǰ����������黺�壬��������û�����EBO�����ˡ�
//
////	// ..:: ��ʼ������ :: ..
////// 1. �󶨶����������
////	glBindVertexArray(VAO);
////	// 2. �����ǵĶ������鸴�Ƶ�һ�����㻺���У���OpenGLʹ��
////	glBindBuffer(GL_ARRAY_BUFFER, VBO);
////	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
////	// 3. �������ǵ��������鵽һ�����������У���OpenGLʹ��
////	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
////	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
////	// 4. �趨��������ָ��
////	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
////	glEnableVertexAttribArray(0);
////
////	[...]
////
////	// ..:: ���ƴ��루��Ⱦѭ���У� :: ..
////	glUseProgram(shaderProgram);
////	glBindVertexArray(VAO);
////	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
////	glBindVertexArray(0);
//#pragma endregion
//
//}
//#pragma endregion
//void drawTrianglesLoop() {
//	//ourShdaer.Use();
//#pragma region ������ɫ��shader���в���
//	//float time = glfwGetTime();
////float g = sin(time) * 0.5f + 0.5f;
////int pos = glGetUniformLocation(shaderProgram, "ourColor");
////glUniform4f(pos, 0.0f, g, 0.0f, 1.0f);
//#pragma endregion
//
//	glBindVertexArray(VAO);
//	glDrawArrays(GL_TRIANGLES, 0, 3);
//#pragma region EBO
//	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//	//glBindVertexArray(0);
//#pragma endregion
//	
//}
//
//int main()
//{
//	glfwInit();
//	//����OpenGL 3.3
//	//���汾��(Major)��Ϊ3
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	//�ΰ汾��(Minor)����Ϊ3
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//	//����glfwCreateWindow(width,hight,title,ignore,ignore)
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//#pragma region glad��ʼ��
//	//GLFW�ṩglfwGetProcAddress��Ϊ��������ϵͳ��ص�OpenGL����ָ���ַ�ĺ���
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to init GLAD" << std::endl;
//		return -1;
//	}
//#pragma endregion
//
//#pragma region �ӿ�
//	//glViewport(���ƴ������½�X,���ƴ������½�Y,������Ⱦ���ڵĿ��(���أ�,������Ⱦ���ڵĿ�Ⱥ͸߶ȣ����أ�)
//	glViewport(0, 0, 800, 600);
//
//	//ע:����ʵ����Ҳ���Խ��ӿڵ�ά������Ϊ��GLFW��ά��С��
//	//������֮�����е�OpenGL��Ⱦ������һ����С�Ĵ�������ʾ��
//	//�����ӵĻ�����Ҳ���Խ�һЩ����Ԫ����ʾ��OpenGL�ӿ�֮�⡣
//
//	//ע:OpenGLĻ��ʹ��glViewport�ж����λ�úͿ�߽���2D�����ת����
//	//��OpenGL�е�λ������ת��Ϊ�����Ļ���ꡣ���磬OpenGL�е�����(-0.5, 0.5)�п��ܣ����գ���ӳ��Ϊ��Ļ�е�����(200,450)��
//	//ע�⣬�������OpenGL���귶ΧֻΪ-1��1�����������ʵ�Ͻ�(-1��1)��Χ�ڵ�����ӳ�䵽(0, 800)��(0, 600)��
//
//	//�����ڱ���һ����ʾ��ʱ��framebuffer_size_callbackҲ�ᱻ���á���������Ĥ(Retina)��ʾ����width��height�������Ա�ԭ����ֵ����һ�㡣
//	//���ǻ����Խ����ǵĺ���ע�ᵽ�����ܶ�Ļص������С�����˵�����ǿ��Դ���һ���ص������������ֱ�����仯�����������Ϣ�ȡ����ǻ��ڴ�������֮����Ⱦѭ����ʼ��֮ǰע����Щ�ص�������
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//#pragma endregion
//#pragma region ����ͼ�γ�ʼ��
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	unsigned int VBO;
//	//����һ�����л���ID��VBO����
//	glGenBuffers(1, &VBO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	Shader ourShdaer = Shader("C:/Users/Yalla/Desktop/Opengl/Shader/3.3.shader.vs", "C:/Users/Yalla/Desktop/Opengl/Shader/3.3.shader.fs");
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//
//#pragma endregion
//
//#pragma region �߿�ģʽ(Wireframe Mode)
//	//Ҫ�����߿�ģʽ������������Σ������ͨ��glPolygonMode(GL_FRONT_AND_BACK, GL_LINE)��������OpenGL��λ���ͼԪ��
//	//��һ��������ʾ���Ǵ��㽫��Ӧ�õ����е������ε�����ͱ��棬
//	//�ڶ������������������������ơ�֮��Ļ��Ƶ��û�һֱ���߿�ģʽ���������Σ�ֱ��������glPolygonMode(GL_FRONT_AND_BACK, GL_FILL)�������û�Ĭ��ģʽ��
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//#pragma endregion
//
//	
//
//
//	//glfwWindowShouldClose����������ÿ��ѭ���Ŀ�ʼǰ���һ��GLFW�Ƿ�Ҫ���˳���
//	//����ǵĻ����ú�������true����Ⱦѭ����ֹͣ���У�֮�����ǾͿ��Թر�Ӧ�ó���
//	while (!glfwWindowShouldClose(window))
//	{
//		//ÿ֡��ⰴ������
//		processInput(window);
//
//#pragma region ��Ⱦѭ��(Render Loop)
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		//����ͨ������glClear�����������Ļ����ɫ���壬������һ������λ(Buffer Bit)��ָ��Ҫ��յĻ��壬
//		//���ܵĻ���λ��GL_COLOR_BUFFER_BIT��GL_DEPTH_BUFFER_BIT��GL_STENCIL_BUFFER_BIT��
//		glClear(GL_COLOR_BUFFER_BIT);
//		
//		ourShdaer.Use();
//#pragma region ������ɫ��shader���в���
//		float time = glfwGetTime();
//		float g = sin(time) * 0.5f + 0.5f;
//		ourShdaer.SetFloat("ourColor", g);
//	//int pos = glGetUniformLocation(shaderProgram, "ourColor");
//	//glUniform4f(pos, 0.0f, g, 0.0f, 1.0f);
//#pragma endregion
//
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//#pragma endregion
//
//
//		//glfwSwapBuffers�����ύ����ɫ���壨����һ��������GLFW����ÿһ��������ɫֵ�Ĵ󻺳壩��������һ�����б��������ƣ����ҽ�����Ϊ�����ʾ����Ļ�ϡ�
//		glfwSwapBuffers(window);
//
//		//ע:˫����(Double Buffer)
//		//Ӧ�ó���ʹ�õ������ͼʱ���ܻ����ͼ����˸�����⡣ ������Ϊ���ɵ�ͼ����һ���ӱ����Ƴ����ģ����ǰ��մ����ң����϶��������صػ��ƶ��ɵġ�
//		//����ͼ������˲����ʾ���û�������ͨ��һ��һ�����ɵģ���ᵼ����Ⱦ�Ľ���ܲ���ʵ��Ϊ�˹����Щ���⣬����Ӧ��˫������Ⱦ����Ӧ�ó���
//		//ǰ���屣�������������ͼ����������Ļ����ʾ�������еĵ���Ⱦָ����ں󻺳��ϻ��ơ�
//		//�����е���Ⱦָ��ִ����Ϻ����ǽ���(Swap)ǰ����ͺ󻺳壬����ͼ����������Գ�����֮ǰ�ᵽ�Ĳ���ʵ�о������ˡ�
//
//		//glfwPollEvents���������û�д���ʲô�¼�������������롢����ƶ��ȣ������´���״̬�������ö�Ӧ�Ļص�����������ͨ���ص������ֶ����ã���
//		glfwPollEvents();
//
//	}
//
//	//��Ⱦѭ����������Ҫ��ȷ�ͷ�/ɾ��֮ǰ�ķ����������Դ
//	glfwTerminate();
//	return 0;
//}
//
