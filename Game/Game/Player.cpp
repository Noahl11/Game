#include "Player.h"


Player::Player(Object model, glm::vec3 position, float rotX, float rotY, float rotZ, float scale) 
				: Entity(model, position, rotX, rotY, rotZ, scale) {
}


Player::~Player()
{
}

void Player::move() {

	increaseRotaion(0.0f, m_currentRotation, 0.0f);
	float distance = m_speed;
	//float strafDistance = m_strafSpeed;
	float dx = float(distance * glm::sin(glm::radians(getRotY())));
	float dz = float(distance * glm::cos(glm::radians(getRotY())));
	//float sx = float(strafDistance * glm::sin(glm::radians(getRotY()) + glm::half_pi));
	//float sz = float(strafDistance * glm::cos(glm::radians(getRotY()) + glm::half_pi)); //Error glm::half_pi uncomment out to see

	increasePosition(dx, 0.0f, dz);
	//increasePosition(sx, 0.0f, sz);

	increasePosition(0.0f, m_upSpeed, 0.0f);

	playerInput();

}

void Player::playerInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_KEYDOWN:
			switch (evnt.key.keysym.sym) {
			case SDLK_w:
				m_speed = m_walk;
				break;
			case SDLK_s:
				m_speed = -m_walk;
				break;
			case SDLK_LSHIFT:
				m_upSpeed = -m_walk;
				break;
			case SDLK_SPACE:
				m_upSpeed = m_walk;
				break;
			}
		}

	}
}