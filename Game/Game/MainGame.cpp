#include "MainGame.h"


MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::run() {
	init();

	m_object.init(-1.0f, -1.0f, 2.0f, 2.0f);

	gameLoop();
}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_window.create("GAME", m_screenWidth, m_screenHeight, 0);

	initShaders();
}

void MainGame::initShaders() {
	m_shaders.compileShaders("Shaders/vertexShader.vert", "Shaders/fragmentShader.frag");
	m_shaders.addAttribute("vertexPosition");
	m_shaders.linkShaders();
}

void MainGame::gameLoop() {
	while (m_gameState == GameState::PLAY) {
		processInput();
		m_time += 0.05;
		m_fps_frames++;
		if (m_fps_lasttime < SDL_GetTicks() - 1 * 1000)
		{
			m_fps_lasttime = SDL_GetTicks();
			m_fps_current = m_fps_frames;
			m_fps_frames = 0;
		}

		//printf("%d \n", m_fps_current);

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

	GLint timeLocation = m_shaders.getUniformLocation("time");
	glUniform1f(timeLocation, m_time);

	m_object.draw();

	m_shaders.unuse();

	m_window.swapBuffer();
}