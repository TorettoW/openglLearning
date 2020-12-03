#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


const unsigned int  SCR_WIDTH = 800;
const unsigned int  SCR_HEIGHT = 600;

int main() {
	//��ʼ��GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    //ʹ��GLFW����window,���ж�windowָ���Ƿ�Ϊ��
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH,SCR_HEIGHT,"MyColorWindow",NULL,NULL);
	if (window == NULL) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
	//��ʼ��GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}

	//ѭ����Ⱦ
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.5f, 0.3f, 0.3f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}


	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0,0,width,height);
}

void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window,true);
}