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

	m_camera.init(300, 300);

	initShaders();
}

void MainGame::initShaders() {
	m_shaders.compileShaders("Shaders/vertexShader.vert", "Shaders/fragmentShader.frag");
	m_shaders.addAttribute("vertexPosition");
	m_shaders.addAttribute("vertexColor");
	m_shaders.linkShaders();
}

void MainGame::gameLoop() {
	while (m_gameState == GameState::PLAY) {
		processInput();
		drawGame();
	}
}

void MainGame::processInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
			case SDL_QUIT:
				m_gameState = GameState::EXIT;
				break;
		}
		
	}
}

void MainGame::drawGame() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_shaders.use();

	GLint cLocation = m_shaders.getUniformLocation("M");
	glm::mat4 cameraMatrix = m_camera.getCameraMatrix();

	glUniformMatrix4fv(cLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	m_shaders.unuse();

	m_window.swapBuffer();
}