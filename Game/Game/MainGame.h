#pragma once
#include <sdl\SDL.h>
#include <GL\glew.h>

#include "Window.h"
#include "GLSLContex.h"

enum class GameState {
	PLAY,
	EXIT
};

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
	GLSLContex m_shaders;
};

