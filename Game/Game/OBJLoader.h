#pragma once

#include <vector>
#include <glm\glm.hpp>

class OBJLoader
{
public:
	OBJLoader();
	~OBJLoader();

	bool load(
		const char * path,
		std::vector < glm::vec3 > & out_vertices,
		std::vector < glm::vec2 > & out_uvs,
		std::vector < glm::vec3 > & out_normals
		);


private:

	std::vector< unsigned int > m_vertexIndices, m_uvIndices, m_normalIndices;
	std::vector< glm::vec3 > m_temp_vertices;
	std::vector< glm::vec2 > m_temp_uvs;
	std::vector< glm::vec3 > m_temp_normals;
};

