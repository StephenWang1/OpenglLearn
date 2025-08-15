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
	//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
};

unsigned int indices[] = {
	// 注意索引从0开始! 
	// 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
	// 这样可以由下标代表顶点组合成矩形

	0, 1, 3, // 第一个三角形
	1, 2, 3  // 第二个三角形
};
GLFWwindow* window;
float lastX = 400, lastY = 300;
float yaw = 0, pitch = 0; //偏航角, 俯仰角
bool firstMouse = true;
//窗口尺寸改变回调
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

#pragma region 输入
void processInput(GLFWwindow* window) {
	//没有按下会返回GLFW_RELEASE
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
	//基于OpenGL 3.3
	//主版本号(Major)设为3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//次版本号(Minor)都设为3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//参数glfwCreateWindow(width,hight,title,ignore,ignore)
	window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

#pragma region glad初始化
	//GLFW提供glfwGetProcAddress作为用来加载系统相关的OpenGL函数指针地址的函数
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to init GLAD" << std::endl;
		return -1;
	}
#pragma endregion

#pragma region 视口
	//glViewport(控制窗口左下角X,控制窗口左下角Y,控制渲染窗口的宽度(像素）,控制渲染窗口的宽度和高度（像素）)
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
#pragma endregion
#pragma region 绘制图形初始化
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	//生成一个带有缓冲ID的VBO对象
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

#pragma region 线框模式(Wireframe Mode)
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#pragma endregion

#pragma region 纹理
	//加载
	int width, height, nrChannels;
	unsigned char* data = stbi_load("C:/Users/Yalla/Desktop/Opengl/Resources/container.jpg", &width, &height, &nrChannels, 0);

	//创建对象
	
	//glGenTextures函数首先需要输入生成纹理的数量，然后把它们储存在第二个参数的unsigned int数组中（我们的例子中只是单独的一个unsigned int）
	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0);
	//绑定
	glBindTexture(GL_TEXTURE_2D, texture);

	// 为当前绑定的纹理对象设置环绕、过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data)
	{
		//生成
		//当调用glTexImage2D时，当前绑定的纹理对象就会被附加上纹理图像
		//第一个参数指定了纹理目标(Target)。设置为GL_TEXTURE_2D意味着会生成与当前绑定的纹理对象在同一个目标上的纹理（任何绑定到GL_TEXTURE_1D和GL_TEXTURE_3D的纹理不会受到影响）。
		//第二个参数为纹理指定多级渐远纹理的级别，如果你希望单独手动设置每个多级渐远纹理的级别的话。这里我们填0，也就是基本级别。
		//第三个参数告诉OpenGL我们希望把纹理储存为何种格式。我们的图像只有RGB值，因此我们也把纹理储存为RGB值。
		//第四个和第五个参数设置最终的纹理的宽度和高度。我们之前加载图像的时候储存了它们，所以我们使用对应的变量。
		//下个参数应该总是被设为0（历史遗留的问题）。
		//第七第八个参数定义了源图的格式和数据类型。我们使用RGB值加载这个图像，并把它们储存为char(byte)数组，我们将会传入对应值。
		//第九个参数是真正的图像数据。
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		//生成mipmap
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else 
	{
		std::cout << "Failed to laod texture" << std::endl;
	}

	//释放纹理
	stbi_image_free(data);


	//加载第二个图
	 
	//能够在图像加载时帮助我们翻转y轴，只需要在加载任何图像前加入以下语句即可：
	stbi_set_flip_vertically_on_load(true); 
	unsigned char* data1 = stbi_load("C:/Users/Yalla/Desktop/Opengl/Resources/awesomeface.png", &width, &height, &nrChannels, 0);

	//创建对象
	
	//glGenTextures函数首先需要输入生成纹理的数量，然后把它们储存在第二个参数的unsigned int数组中（我们的例子中只是单独的一个unsigned int）
	glGenTextures(1, &texture1);

	glActiveTexture(GL_TEXTURE1);
	//绑定
	glBindTexture(GL_TEXTURE_2D, texture1);

	// 为当前绑定的纹理对象设置环绕、过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data1)
	{
		
		//生成
		//当调用glTexImage2D时，当前绑定的纹理对象就会被附加上纹理图像
		//第一个参数指定了纹理目标(Target)。设置为GL_TEXTURE_2D意味着会生成与当前绑定的纹理对象在同一个目标上的纹理（任何绑定到GL_TEXTURE_1D和GL_TEXTURE_3D的纹理不会受到影响）。
		//第二个参数为纹理指定多级渐远纹理的级别，如果你希望单独手动设置每个多级渐远纹理的级别的话。这里我们填0，也就是基本级别。
		//第三个参数告诉OpenGL我们希望把纹理储存为何种格式。我们的图像只有RGB值，因此我们也把纹理储存为RGB值。
		//第四个和第五个参数设置最终的纹理的宽度和高度。我们之前加载图像的时候储存了它们，所以我们使用对应的变量。
		//下个参数应该总是被设为0（历史遗留的问题）。
		//第七第八个参数定义了源图的格式和数据类型。我们使用RGB值加载这个图像，并把它们储存为char(byte)数组，我们将会传入对应值。
		//第九个参数是真正的图像数据。
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data1);

		//生成mipmap
		glGenerateMipmap(GL_TEXTURE_2D);
	
	}
	else
	{
		std::cout << "Failed to laod texture" << std::endl;
	}

	//释放纹理
	stbi_image_free(data1);
	// 不要忘记在设置uniform变量之前激活着色器程序！
	ourShdaer.Use();
	//设置每个采样器的方式告诉OpenGL每个着色器采样器属于哪个纹理单元,只需要设置一次
	glUniform1i(glGetUniformLocation(ourShdaer.ID, "texture1"), 1);
	ourShdaer.SetInt("texture2", 0);

#pragma endregion


	//glfwWindowShouldClose函数在我们每次循环的开始前检查一次GLFW是否被要求退出，
	//如果是的话，该函数返回true，渲染循环将停止运行，之后我们就可以关闭应用程序。
	while (!glfwWindowShouldClose(window))
	{
		//每帧检测按键输入
		processInput(window);

#pragma region 渲染循环(Render Loop)
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//可以通过调用glClear函数来清空屏幕的颜色缓冲，它接受一个缓冲位(Buffer Bit)来指定要清空的缓冲，
		//可能的缓冲位有GL_COLOR_BUFFER_BIT，GL_DEPTH_BUFFER_BIT和GL_STENCIL_BUFFER_BIT。
		glClear(GL_COLOR_BUFFER_BIT);

		
#pragma region 输入颜色到shader公有参数
		float time = glfwGetTime();
		float g = sin(time) * 0.5f + 0.5f;
		ourShdaer.SetFloat("ourColor", g);
		//int pos = glGetUniformLocation(shaderProgram, "ourColor");
		//glUniform4f(pos, 0.0f, g, 0.0f, 1.0f);
#pragma endregion
		//绑定纹理
		glBindTexture(GL_TEXTURE_2D, texture);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glActiveTexture(GL_TEXTURE1);

		//绘制三角形
		//glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		ourShdaer.Use();
#pragma region EBO
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glBindVertexArray(0);
#pragma endregion
#pragma endregion


		//glfwSwapBuffers函数会交换颜色缓冲（它是一个储存着GLFW窗口每一个像素颜色值的大缓冲），它在这一迭代中被用来绘制，并且将会作为输出显示在屏幕上。
		glfwSwapBuffers(window);

		//glfwPollEvents函数检查有没有触发什么事件（比如键盘输入、鼠标移动等）、更新窗口状态，并调用对应的回调函数（可以通过回调方法手动设置）。
		glfwPollEvents();

	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	//渲染循环结束后需要正确释放/删除之前的分配的所有资源
	glfwTerminate();
	return 0;
}

void Test() {
	glm::mat4 trans = glm::mat4(1.0f);
	//可视空间的大平截头体
	// 参数1:定义了fov的值，它表示的是视野(Field of View)，并且设置了观察空间的大小。如果想要一个真实的观察效果，它的值通常设置为45.0f，
	// 但想要一个毁灭战士(DOOM,经典的系列第一人称射击游戏)风格的结果你可以将其设置一个更大的值。
	// 参数二:设置了宽高比，由视口的宽除以高所得。
	// 参数三:设置了平截头体的近平面
	// 参数四:设置了平截头体的远平面。
	// 我们通常设置近距离为0.1f，而远距离设为100.0f。所有在近平面和远平面内且处于平截头体内的顶点都会被渲染。
	//glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	//注:当你把透视矩阵的 near 值设置太大时（如10.0f），OpenGL会将靠近摄像机的坐标（在0.0f和10.0f之间）都裁剪掉，
	//这会导致一个你在游戏中很熟悉的视觉效果：在太过靠近一个物体的时候你的视线会直接穿过去。
}

void BuildCamera() {
	//基于右手坐标系

	//1相机位置
	//
	//正z轴是从屏幕指向你的，如果我们希望摄像机向后移动，我们就沿着z轴的正方向移动。
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);

	//2相机方向
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);//场景坐标原点
	glm::vec3 cameraDirection = glm::normalize(cameraTarget - cameraPos);//相机指向坐标原点

	//3相机空间右轴 x正方向
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	//为获取右向量我们需要先使用一个小技巧：先定义一个上向量(Up Vector)。
	//接下来把上向量和第二步得到的方向向量进行叉乘。两个向量叉乘的结果会同时垂直于两向量，因此我们会得到指向x轴正方向的那个向量
	//（如果我们交换两个向量叉乘的顺序就会得到相反的指向x轴负方向的向量）
	glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	//4上轴 正y轴向量
	glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

	//注:格拉姆—施密特正交化(Gram-Schmidt Process)。使用这些摄像机向量我们就可以创建一个LookAt矩阵了，它在创建摄像机的时候非常有用。
	//在三维空间中，叉乘是施密特正交化的几何实现，两者在数学上等价

	glm::mat4 view = glm::lookAt(cameraPos, cameraTarget, up);

}
void mouse_callback(GLFWwindow* window,double xpos,double ypos ) {

	if (firstMouse) // 这个bool变量初始时是设定为true的
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // 注意这里是相反的，因为y坐标是从底部往顶部依次增大的
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