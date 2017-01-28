#include "Camera.h"


Camera::Camera() : m_position(0.0f, 0.0f, 0.0f), m_cameraMatrix(1.0f), m_persMatrix(1.0f), 
					m_needsMatrixUpdate(true), m_screenWidth(500), m_screenHeight(500)
{
}


Camera::~Camera()
{
}

void Camera::init(int screenWidth, int screenHeight) {
	m_screenWidth = m_screenWidth;
	m_screenHeight = m_screenHeight;
	m_persMatrix = glm::perspective(glm::radians(45.0f), (float)m_screenWidth / (float)m_screenHeight, 0.1f, 100.0f);
}

void Camera::update() {
	if (m_needsMatrixUpdate) {
		glm::vec3 translate(m_position.x, m_position.y, m_position.z);
		m_cameraMatrix = glm::translate(m_persMatrix, translate);

		m_needsMatrixUpdate = false;
	}
}