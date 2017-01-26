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

	glm::vec2 convertScreenToWorld(glm::vec2 screenCoords);

	//bool isBoxInView(const glm::vec2& position, const glm::vec2 dimentions);


};

