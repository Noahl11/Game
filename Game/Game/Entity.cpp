#include "Entity.h"


Entity::Entity(Object model, glm::vec3 position, float rotX, float rotY, float rotZ, float scale) {
	m_object = model;
	m_position = position;
	m_rotX = rotX;
	m_rotY = rotY;
	m_rotZ = rotZ;
	m_scale = scale;
}


Entity::~Entity()
{
}

void Entity::increasePosition(float dx, float dy, float dz) {
	m_position.x += dx;
	m_position.y += dy;
	m_position.z += dz;
}

void Entity::increaseRotaion(float dx, float dy, float dz) {
	m_rotX += dx;
	m_rotY += dy;
	m_rotZ += dz;
}