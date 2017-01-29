#pragma once

#include "Object.h"

class Entity
{
public:
	Entity(Object model, glm::vec3, float rotX, float rotY, float rotZ, float scale);
	~Entity();

	void increasePosition(float dx, float dy, float dz); 
	void increaseRotaion(float dx, float dy, float dz);

	void setPos(glm::vec3 pos) { m_position = pos; }

	glm::vec3 getPos() { return m_position; }

	float getRotX() { return m_rotX; }
	float getRotY() { return m_rotY; }
	float getRotZ() { return m_rotZ; }

private:
	Object m_object;

	glm::vec3 m_position;

	float m_rotX, m_rotY, m_rotZ;
	float m_scale;
};