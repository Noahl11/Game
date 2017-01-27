#pragma once
#include <sdl\SDL.h>
#include <GL\glew.h>

#include "Window.h"
#include "GLSLContex.h"
#include "Camera.h"
#include "Object.h"


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
	void processInput();
	void drawGame();

	int m_screenWidth = 1024;
	int m_screenHeight = 720;

	Window m_window;
	GLSLContex m_shaders;
	GameState m_gameState;
	Camera m_camera;
	Object m_object;
};

