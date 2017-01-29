#pragma once

#include <glm\glm.hpp>

class SoildPhysics
{
public:
	SoildPhysics();
	~SoildPhysics();
private:
	glm::vec3 Velocity();
	float Gravity(float mass1, float mass2, float distance);
};

