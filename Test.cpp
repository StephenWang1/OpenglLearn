//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include "Shader.h"
//
////窗口尺寸改变回调
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//#pragma region 输入
//void processInput(GLFWwindow* window) {
//	//没有按下会返回GLFW_RELEASE
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, true);
//	}
//}
//#pragma endregion
//
//#pragma region 三角形绘制
////顶点数组对象：Vertex Array Object，VAO
////顶点缓冲对象：Vertex Buffer Object，VBO
////元素缓冲对象：Element Buffer Object，EBO 或 索引缓冲对象 Index Buffer Object，IBO
//
//#pragma region 顶点着色器
////每个着色器都起始于一个版本声明。OpenGL 3.3以及和更高版本中，GLSL版本号和OpenGL的版本是匹配的（比如说GLSL 420版本对应于OpenGL 4.2）。
////我们同样明确表示我们会使用核心模式。
////#version 330 core
//// layout (location = 0)设定了输入变量的位置值(Location)
////使用in关键字，在顶点着色器中声明所有的输入顶点属性(Input Vertex Attribute)。
////layout(location = 0) in vec3 aPos;
////void main()
////{
//   // gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
////}
//#pragma endregion
//#pragma region 片元着色器
////#version 330 core
//// out 声明输出变量
////out vec4 FragColor;
//
////void main()
////{
//	//FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
////}
//#pragma endregion
//
//#pragma region 编译着色器
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
//	// 位置              // 颜色
//	0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
//   -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
//	0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
//};
//
//unsigned int indices[] = {
//	// 注意索引从0开始! 
//	// 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
//	// 这样可以由下标代表顶点组合成矩形
//
//	0, 1, 3, // 第一个三角形
//	1, 2, 3  // 第二个三角形
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
//	//生成一个带有缓冲ID的VBO对象
//	glGenBuffers(1, &VBO);
//	//顶点缓冲对象的缓冲类型是GL_ARRAY_BUFFER, OpenGL有很多缓冲对象类型.
//	// OpenGL允许同时绑定多个缓冲，只要它们是不同的缓冲类型。使用glBindBuffer函数把新创建的缓冲绑定到GL_ARRAY_BUFFER目标上：
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//glBufferData是一个专门用来把用户定义的数据复制到当前绑定缓冲的函数。
//	//第一个参数是目标缓冲的类型：顶点缓冲对象当前绑定到GL_ARRAY_BUFFER目标上。
//	//第二个参数指定传输数据的大小(以字节为单位)；用一个简单的sizeof计算出顶点数据大小就行。
//	//第三个参数是我们希望发送的实际数据。
//	/*第四个参数指定了我们希望显卡如何管理给定的数据。它有三种形式：
//		GL_STATIC_DRAW ：数据不会或几乎不会改变。
//		GL_DYNAMIC_DRAW：数据会被改变很多。
//		GL_STREAM_DRAW ：数据每次绘制时都会改变。
//	三角形的位置数据不会改变，每次渲染调用时都保持原样，所以它的使用类型最好是GL_STATIC_DRAW。
//	如果，比如说一个缓冲中的数据将频繁被改变，那么使用的类型就是GL_DYNAMIC_DRAW或GL_STREAM_DRAW，这样就能确保显卡把数据放在能够高速写入的内存部分。*/
//	//将顶点数据储存在显卡的内存中，用VBO这个顶点缓冲对象管理。
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
////#pragma region 编译着色器
////#pragma region 顶点着色器
////	unsigned int vertexShader;
////	vertexShader = glCreateShader(GL_VERTEX_SHADER);
////	//glShaderSource函数把要编译的着色器对象作为第一个参数。
////	//第二参数指定了传递的源码字符串数量，这里只有一个。
////	//第三个参数是顶点着色器真正的源码，
////	//第四个参数我们先设置为NULL。
////	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
////	glCompileShader(vertexShader);
////	int success;
////	char infoLog[512];
////	//检测在调用glCompileShader后编译是否成功
////	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
////	if (!success)
////	{
////		//glGetShaderInfoLog获取错误消息
////		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
////		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
////	}
////#pragma endregion
////#pragma region 片元着色器
////	unsigned int fragmentShader;
////	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
////	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
////	glCompileShader(fragmentShader);
////	//检测在调用glCompileShader后编译是否成功
////	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
////	if (!success)
////	{
////		//glGetShaderInfoLog获取错误消息
////		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
////		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
////	}
////
////#pragma endregion
////
////#pragma region 着色器程序(Shader Program)
////	//着色器程序对象(Shader Program Object)是多个着色器合并之后并最终链接完成的版本
////	
////	shaderProgram = glCreateProgram();
////	glAttachShader(shaderProgram, vertexShader);
////	glAttachShader(shaderProgram, fragmentShader);
////	glLinkProgram(shaderProgram);
////
////	//检测在调用glCompileShader后编译是否成功
////	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
////	if (!success)
////	{
////		//glGetShaderInfoLog获取错误消息
////		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
////		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
////	}
////	//glUseProgram 激活程序对象
////	glUseProgram(shaderProgram);
////	glDeleteShader(vertexShader);
////	glDeleteShader(fragmentShader);
////	//已经把输入顶点数据发送给了GPU，并指示了GPU如何在顶点和片段着色器中处理它
////#pragma endregion
//	//Shader ourShdaer("3.3.shader.vs", "3.3.shader.fs");
//	glBindVertexArray(VAO);
//	glDrawArrays(GL_TRIANGLES, 0, 3);
//
//#pragma endregion
//#pragma region 链接顶点属性
////第一个参数指定我们要配置的顶点属性。还记得我们在顶点着色器中使用layout(location = 0)定义了position顶点属性的位置值(Location)吗？
//// 它可以把顶点属性的位置值设置为0。因为我们希望把数据传递到这一个顶点属性中，所以这里我们传入0。
////第二个参数指定顶点属性的大小。顶点属性是一个vec3，它由3个值组成，所以大小是3。
////第三个参数指定数据的类型，这里是GL_FLOAT(GLSL中vec * 都是由浮点数值组成的)。
////第四个参数定义我们是否希望数据被标准化(Normalize)。如果我们设置为GL_TRUE，所有数据都会被映射到0（对于有符号型signed数据是 - 1）到1之间。我们把它设置为GL_FALSE。
////第五个参数叫做步长(Stride)，它告诉我们在连续的顶点属性组之间的间隔。由于下个组位置数据在3个float之后，我们把步长设置为3 * sizeof(float)。
//// 要注意的是由于我们知道这个数组是紧密排列的（在两个顶点属性之间没有空隙）我们也可以设置为0来让OpenGL决定具体步长是多少（只有当数值是紧密排列时才可用）。
//// 一旦我们有更多的顶点属性，我们就必须更小心地定义每个顶点属性之间的间隔，
//// 我们在后面会看到更多的例子（译注: 这个参数的意思简单说就是从这个属性第二次出现的地方到整个数组0位置之间有多少字节）。
////第六个参数的类型是void * ，所以需要我们进行这个奇怪的强制类型转换。它表示位置数据在缓冲中起始位置的偏移量(Offset)。由于位置数据在数组的开头，所以这里是0。
////我们会在后面详细解释这个参数。
////glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
////glEnableVertexAttribArray(0);
////注:每个顶点属性从一个VBO管理的内存中获得它的数据，而具体是从哪个VBO（程序中可以有多个VBO）获取则是通过在调用glVertexAttribPointer时绑定到GL_ARRAY_BUFFER的VBO决定的。
////由于在调用glVertexAttribPointer之前绑定的是先前定义的VBO对象，顶点属性0现在会链接到它的顶点数据。
//
////// 0. 复制顶点数组到缓冲中供OpenGL使用
////glBindBuffer(GL_ARRAY_BUFFER, VBO);
////glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
////// 1. 设置顶点属性指针
////glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
////glEnableVertexAttribArray(0);
////// 2. 当我们渲染一个物体时要使用着色器程序
////glUseProgram(shaderProgram);
////// 3. 绘制物体
////someOpenGLFunctionThatDrawsOurTriangle();
//#pragma endregion
//
//#pragma region 顶点数组对象(Vertex Array Object, VAO)
//	//注:OpenGL的核心模式要求我们使用VAO，所以它知道该如何处理我们的顶点输入。如果我们绑定VAO失败，OpenGL会拒绝绘制任何东西。
//	//unsigned int VAO;
//	//glGenVertexArrays(1, &VAO);
//
//	//// ..:: 初始化代码（只运行一次 (除非你的物体频繁改变)） :: ..
//	//// 1. 绑定VAO
//	//glBindVertexArray(VAO);
//	//// 2. 把顶点数组复制到缓冲中供OpenGL使用
//	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	//// 3. 设置顶点属性指针
//	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	//glEnableVertexAttribArray(0);
//
//	//[...]
//
//	//// ..:: 绘制代码（渲染循环中） :: ..
//	//// 4. 绘制物体
//	//glUseProgram(shaderProgram);
//	//glBindVertexArray(VAO);
//	//someOpenGLFunctionThatDrawsOurTriangle();
//#pragma endregion
//
//#pragma region 元素缓冲对象(Element Buffer Object，EBO)，或索引缓冲对象(Index Buffer Object，IBO)
//	//EBO是一个缓冲区，就像一个顶点缓冲区对象一样，它存储 OpenGL 用来决定要绘制哪些顶点的索引。
//	//这种所谓的索引绘制(Indexed Drawing)正是我们问题的解决方案
//	//unsigned int EBO;
//	//glGenBuffers(1, &EBO);
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	// 第一个参数指定了绘制的模式，这个和glDrawArrays的一样。
//	// 第二个参数是打算绘制顶点的个数，这里填6，也就是说我们一共需要绘制6个顶点。
//	// 第三个参数是索引的类型，这里是GL_UNSIGNED_INT。
//	// 第四个参数里可以指定EBO中的偏移量（或者传递一个索引数组，但是这是当你不在使用索引缓冲对象的时候），但是我们会在这里填写0。
//	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//	//在绑定VAO时，绑定的最后一个元素缓冲区对象存储为VAO的元素缓冲区对象。然后，绑定到VAO也会自动绑定该EBO。
//	
//	//注:当目标是GL_ELEMENT_ARRAY_BUFFER的时候，VAO会储存glBindBuffer的函数调用。
//	//这也意味着它也会储存解绑调用，所以确保你没有在解绑VAO之前解绑索引数组缓冲，否则它就没有这个EBO配置了。
//
////	// ..:: 初始化代码 :: ..
////// 1. 绑定顶点数组对象
////	glBindVertexArray(VAO);
////	// 2. 把我们的顶点数组复制到一个顶点缓冲中，供OpenGL使用
////	glBindBuffer(GL_ARRAY_BUFFER, VBO);
////	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
////	// 3. 复制我们的索引数组到一个索引缓冲中，供OpenGL使用
////	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
////	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
////	// 4. 设定顶点属性指针
////	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
////	glEnableVertexAttribArray(0);
////
////	[...]
////
////	// ..:: 绘制代码（渲染循环中） :: ..
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
//#pragma region 输入颜色到shader公有参数
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
//	//基于OpenGL 3.3
//	//主版本号(Major)设为3
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	//次版本号(Minor)都设为3
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//	//参数glfwCreateWindow(width,hight,title,ignore,ignore)
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//#pragma region glad初始化
//	//GLFW提供glfwGetProcAddress作为用来加载系统相关的OpenGL函数指针地址的函数
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to init GLAD" << std::endl;
//		return -1;
//	}
//#pragma endregion
//
//#pragma region 视口
//	//glViewport(控制窗口左下角X,控制窗口左下角Y,控制渲染窗口的宽度(像素）,控制渲染窗口的宽度和高度（像素）)
//	glViewport(0, 0, 800, 600);
//
//	//注:我们实际上也可以将视口的维度设置为比GLFW的维度小，
//	//这样子之后所有的OpenGL渲染将会在一个更小的窗口中显示，
//	//这样子的话我们也可以将一些其它元素显示在OpenGL视口之外。
//
//	//注:OpenGL幕后使用glViewport中定义的位置和宽高进行2D坐标的转换，
//	//将OpenGL中的位置坐标转换为你的屏幕坐标。例如，OpenGL中的坐标(-0.5, 0.5)有可能（最终）被映射为屏幕中的坐标(200,450)。
//	//注意，处理过的OpenGL坐标范围只为-1到1，因此我们事实上将(-1到1)范围内的坐标映射到(0, 800)和(0, 600)。
//
//	//当窗口被第一次显示的时候framebuffer_size_callback也会被调用。对于视网膜(Retina)显示屏，width和height都会明显比原输入值更高一点。
//	//我们还可以将我们的函数注册到其它很多的回调函数中。比如说，我们可以创建一个回调函数来处理手柄输入变化，处理错误消息等。我们会在创建窗口之后，渲染循环初始化之前注册这些回调函数。
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//#pragma endregion
//#pragma region 绘制图形初始化
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	unsigned int VBO;
//	//生成一个带有缓冲ID的VBO对象
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
//#pragma region 线框模式(Wireframe Mode)
//	//要想用线框模式绘制你的三角形，你可以通过glPolygonMode(GL_FRONT_AND_BACK, GL_LINE)函数配置OpenGL如何绘制图元。
//	//第一个参数表示我们打算将其应用到所有的三角形的正面和背面，
//	//第二个参数告诉我们用线来绘制。之后的绘制调用会一直以线框模式绘制三角形，直到我们用glPolygonMode(GL_FRONT_AND_BACK, GL_FILL)将其设置回默认模式。
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//#pragma endregion
//
//	
//
//
//	//glfwWindowShouldClose函数在我们每次循环的开始前检查一次GLFW是否被要求退出，
//	//如果是的话，该函数返回true，渲染循环将停止运行，之后我们就可以关闭应用程序。
//	while (!glfwWindowShouldClose(window))
//	{
//		//每帧检测按键输入
//		processInput(window);
//
//#pragma region 渲染循环(Render Loop)
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		//可以通过调用glClear函数来清空屏幕的颜色缓冲，它接受一个缓冲位(Buffer Bit)来指定要清空的缓冲，
//		//可能的缓冲位有GL_COLOR_BUFFER_BIT，GL_DEPTH_BUFFER_BIT和GL_STENCIL_BUFFER_BIT。
//		glClear(GL_COLOR_BUFFER_BIT);
//		
//		ourShdaer.Use();
//#pragma region 输入颜色到shader公有参数
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
//		//glfwSwapBuffers函数会交换颜色缓冲（它是一个储存着GLFW窗口每一个像素颜色值的大缓冲），它在这一迭代中被用来绘制，并且将会作为输出显示在屏幕上。
//		glfwSwapBuffers(window);
//
//		//注:双缓冲(Double Buffer)
//		//应用程序使用单缓冲绘图时可能会存在图像闪烁的问题。 这是因为生成的图像不是一下子被绘制出来的，而是按照从左到右，由上而下逐像素地绘制而成的。
//		//最终图像不是在瞬间显示给用户，而是通过一步一步生成的，这会导致渲染的结果很不真实。为了规避这些问题，我们应用双缓冲渲染窗口应用程序。
//		//前缓冲保存着最终输出的图像，它会在屏幕上显示；而所有的的渲染指令都会在后缓冲上绘制。
//		//当所有的渲染指令执行完毕后，我们交换(Swap)前缓冲和后缓冲，这样图像就立即呈显出来，之前提到的不真实感就消除了。
//
//		//glfwPollEvents函数检查有没有触发什么事件（比如键盘输入、鼠标移动等）、更新窗口状态，并调用对应的回调函数（可以通过回调方法手动设置）。
//		glfwPollEvents();
//
//	}
//
//	//渲染循环结束后需要正确释放/删除之前的分配的所有资源
//	glfwTerminate();
//	return 0;
//}
//
