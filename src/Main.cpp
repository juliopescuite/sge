/*
* Copyright (c) 2023 Julio Cesar Pescuite Goncalves Batista
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "GameEngine.cpp"
#include <GLFW/glfw3.h>

const char* TITLE = "Simple Game Engine: by Julio Batista";
const int WIDTH = 1600;
const int HEIGHT = 1200;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void)
{
	// GLFW initialization, will be moved to the renederer later
	if (!glfwInit())
		return -1;

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, key_callback);

	glfwMakeContextCurrent(window);

	IBase::log("Game Initialization");

	// Setup
	IGameEngine* p_gameEngine = new GameEngine();
	IScene* p_scene = new Scene();
	IGameObject* p_gameObject = new GameObject();

	// Add game object(s) to scene
	p_scene->addGameObject(static_cast<GameObject*>(p_gameObject));

	// Add scene(s) to the game engine
	p_gameEngine->addScene(static_cast<Scene*>(p_scene));

	// Initialize game engine
	p_gameEngine->init();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// Game loop
		p_gameEngine->loop();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	// Game Shutdown
	p_gameEngine->shutdown();

	// Clean up
	delete p_gameEngine;
	p_gameEngine = nullptr;

	IBase::log("Game Shutdown complete");

	return 0;
}