#pragma once

#include "Entity.h"
#include <sdl\SDL.h>
#include <glm\gtc\constants.hpp>

class Player: public Entity
{
public:
	Player(Object model, glm::vec3 position, float rotX, float rotY, float rotZ, float scale);
	~Player();

	void move();

private:
	void playerInput();

	float m_run;
	float m_walk;
	float m_rotate;

	float m_currentRotation;
	float m_speed;
	//float m_strafSpeed;
	float m_upSpeed;
	float m_downSpeed;

};

