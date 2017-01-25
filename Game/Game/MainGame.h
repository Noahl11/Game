#pragma once
#include "../deps/include/sdl/SDL.h"
#include "../deps/include/GL/glew.h"

#include "Window.h"

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:
	void init();
	void gameLoop();
	void initShaders();

	Window m_window;
};

