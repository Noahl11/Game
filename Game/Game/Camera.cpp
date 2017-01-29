#include "Camera.h"


Camera::Camera(Player player) : m_position(0.0f, 0.0f, 0.0f), m_cameraMatrix(1.0f), m_persMatrix(1.0f), 
				m_needsMatrixUpdate(true), m_screenWidth(500), m_screenHeight(500), m_player(player)
{

}


Camera::~Camera()
{
}

void Camera::init(int screenWidth, int screenHeight) {
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
	m_persMatrix = glm::perspective(glm::radians(45.0f), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
}

void Camera::update() {
	if (m_needsMatrixUpdate) {
		glm::vec3 translate(m_position.x, m_position.y, m_position.z - 15.0f);
		glm::mat4 move = glm::translate(m_persMatrix, translate);
		glm::mat4 rotate = glm::rotate(m_persMatrix, m_rotation, glm::vec3(1.0f, 0.0f, 0.0f));
		m_cameraMatrix = move + rotate;
		if (m_rotation >= 1) {
			m_rotation = 1;
		}
		if (m_rotation <= -1) {
			m_rotation = -1;
		}

		m_needsMatrixUpdate = false;
	}
}

void Camera::caculateCameraPosition(float horizontal) {
	float offsetX = float(horizontal * glm::sin(glm::radians(m_player.getRotY())));
	float offsetZ = float(horizontal * glm::cos(glm::radians(m_player.getRotY())));
	m_position.x = m_player.getPos().x - offsetX;
	m_position.z = m_player.getPos().z - offsetZ;
	m_position.y = m_player.getPos().y;
}