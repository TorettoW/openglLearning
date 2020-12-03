#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

const unsigned int  SCR_WIDTH = 800;
const unsigned int  SCR_HEIGHT = 600;

int main() {
	glfwInit();//��ʼ��GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);//ʹ��glfwWindowHint��������GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH,SCR_HEIGHT,"HelloWindow",NULL,NULL);//����windowָ��
	if (window == NULL) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);//֪ͨGLFW����������������Ϊ��ǰ�̵߳���������
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//��ʼ��GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}
	
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwTerminate();

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width ,int height) 
{
	glViewport(0,0,width,height);
}