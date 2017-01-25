#include "Window.h"


Window::Window()
{
}


Window::~Window()
{
}

int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags) {
	Uint32 flags = SDL_WINDOW_OPENGL;

	if (currentFlags & INVISABLE) {
		flags |= SDL_WINDOW_HIDDEN;
	}
	if (currentFlags & FULLSCREEN) {
		flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	}
	if (currentFlags & BORDERLESS) {
		flags |= SDL_WINDOW_BORDERLESS;
	}

	m_sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);

	if (m_sdlWindow == nullptr) {
		//Error Text
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(m_sdlWindow);
	if (glContext == nullptr) {
		//Error Text
	}

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		//Error Text
	}

	std::printf("*** OpenGL Version: %s ***\n", glGetString(GL_VERSION));

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	SDL_GL_SetSwapInterval(1);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return 0;
}

void Window::swapBuffer() {
	SDL_GL_SwapWindow(m_sdlWindow);
}