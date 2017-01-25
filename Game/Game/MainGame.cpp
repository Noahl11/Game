#include "MainGame.h"


MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::run() {
	init();

	gameLoop();
}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_window.create("GAME", 300, 300, 0);

	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

	initShaders();
}

void MainGame::initShaders() {
	m_shaders.compileShaders("Shaders/vertexShader.txt", "Shaders/fragmentShader.txt");
	m_shaders.linkShaders();
}

void MainGame::gameLoop() {
	
}