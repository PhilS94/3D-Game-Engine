#pragma once

#include <iostream>
#include <SDL.h>

class Window
{
public:
	static void createWindow(int width, int heigth, std::string title);
	~Window();
	static void render();
	static void destroy();
	static bool isClosed();
	//inline static int getWidth() { int *w; int *h; SDL_GetWindowSize(window, w, h); return *w; }
	//inline static int getHeigth() { int *w; int *h; SDL_GetWindowSize(window,w,h); return *h; }
	//inline static std::string getTitle() { std::string(SDL_GetWindowTitle(window));}
	//static void getCenter();
private:
	SDL_Window *window;
};

