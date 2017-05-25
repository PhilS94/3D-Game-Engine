#include "Window.h"


void Window::createWindow(int width, int heigth, std::string title) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window;
	try {
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, heigth, SDL_WINDOW_OPENGL);
		//Display.create();
		//Keyboard.create();
		//Mouse.create();
//test
	}
	catch (std::exception& e)
	{
		std::cout << "Failed creating Window: " << e.what() << std::endl;
	}
}

void Window::render() {
	//SDL_UpdateWindowSurface(window);
	//SDL_GL_SwapWindow(window);
}

void Window::destroy() {
	//Display.destroy();
	//Keyboard.destroy();
	//Mouse.destroy();
}

bool Window::isClosed() {
	return true;
}

Window::~Window() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}
