//Main loop
#include "Mineclone.h"

using namespace Mineclone;

int main() 
{
	//checks to make sure GLFW is avalable
	if (!glfwInit()) 
	{
		printf("Failed to initialize GLFW");
		return -1;
	}

	//tells glfw what version lib to use/is installed (3.3) 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//tells glfw what profile to use (Core)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Variable Decleration for glfw
	const int windowWidth = 1280;
	const int windowHeight = 720;
	const char* windowTitle = "Mineclone Powered by ignorance";

	//Window Creation
	GLFWwindow* window = glfwCreateWindow
	(
		windowWidth,
		windowHeight,
		windowTitle,
		nullptr, //Monitor, use glfwPriaryMonitor() for full-screen
		nullptr //Share, use this for resource sharing (typically not needed)
	);
	//checks to make sure window has been initalised
	if (window == nullptr) 
	{
		printf("Failed to create GLFW window\n");
		glfwTerminate();
		return -1;
	}

	//allows openGL to modify/update the window
	glfwMakeContextCurrent(window);

	//checks to make sure glad is avalibale
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		printf("Failed to initialize Glad.\n");
		return -1;
	}

	//tells the postion and size to render the window on screen
	glViewport(0, 0, windowWidth, windowHeight);

	//window/game rendering loop (will run untill Close is called)
	while (!glfwWindowShouldClose(window)) 
	{
		//screen clearing
		glClearColor(250.0f / 255.0f, 119.0f / 255.0f, 110.0f / 255.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); //makes sure the screen is cleared each frame

		glfwSwapBuffers(window); //Double buffering
		glfwPollEvents(); //checks for any new events (e.g. user typing,clicking or resizing)
	}

	//terminates glfw
	glfwTerminate();
	return 0;
}