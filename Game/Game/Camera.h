#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

class Camera
{
public:
	Camera();
	~Camera();

	void init(int screenWidth, int screenHeight);

	void update();

	glm::vec3 convertScreenToWorld(glm::vec3 screenCoords);

	//bool isBoxInView(const glm::vec2& position, const glm::vec2 dimentions);

	void setPosition(const glm::vec3& newPosition) { m_position = newPosition; m_needsMatrixUpdate = true; }

	glm::vec3 getPosition() { return m_position; }

	void setRotation(const float rotation) { m_rotation = rotation; m_needsMatrixUpdate = true; }

	float getRotation() { return m_rotation; }
	glm::mat4 getCameraMatrix() { return m_cameraMatrix; }

private:
	int m_screenWidth, m_screenHeight;
	float m_rotation;
	bool m_needsMatrixUpdate;
	glm::vec3 m_position;
	glm::mat4 m_cameraMatrix;
	glm::mat4 m_persMatrix;
};

