#include <iostream>
#include "Time.h"
#include "../RenderingEngine/Window.h"

#undef main
int main(int argc, char* argv[]) {
	Window::createWindow(600, 480, "Nice Window");

	for (int i = 0; i < 10; i++)
	{
		std::cout << Time::getTime() << std::endl;
		std::cin.ignore();
	}
	std::cout << "Hello World!" << std::endl;
	return 0;
}