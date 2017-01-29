#include "Object.h"

Object::Object()
{
}


Object::~Object()
{
	if (m_vboID != 0) {
		glDeleteBuffers(1, &m_vboID);
	}
}

void Object::init(float x, float y, float z, float width, float height, float depth) {
	m_x = x;
	m_y = y;
	m_z = z;
	m_width = width;
	m_height = height;
	m_depth = depth;

	m_Loader.load("res/cube.obj", m_vertices, m_uvs, m_normals);

	if(m_vboID == 0) {
		glGenBuffers(1, &m_vboID);
	}

	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(glm::vec3), &m_vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Object::draw() {
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());

	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}