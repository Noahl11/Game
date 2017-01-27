#pragma once
#include <sdl\SDL.h>
#include <GL\glew.h>

#include <string>

enum WindowFlags { INVISABLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4 };

class Window
{
public:
	Window();
	~Window();

	int create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);

	void swapBuffer();

	int getScreenWidth() { return m_screenWidth; };
	int getScreenHeight() { return m_screenHeight; };

private:
	SDL_Window* m_sdlWindow;
	int m_screenWidth;
	int m_screenHeight;

};

