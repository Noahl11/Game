#pragma once
#include <GL\glew.h>
#include "OBJLoader.h"

class Object
{
public:
	Object();
	~Object();

	void init(float x, float y, float z, float width, float height, float depth);

	void draw();

private:

	float m_x;
	float m_y;
	float m_z;
	float m_width;
	float m_height;
	float m_depth;
	GLuint m_vboID = 0;
	OBJLoader m_Loader;

	std::vector< glm::vec3 > m_vertices;
	std::vector< glm::vec2 > m_uvs;
	std::vector< glm::vec3 > m_normals;

};

