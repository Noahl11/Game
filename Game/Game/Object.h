#pragma once
#include <GL\glew.h>

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

};

