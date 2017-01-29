#define _CRT_SECURE_NO_DEPRECATE
#include "OBJLoader.h"

OBJLoader::OBJLoader()
{
}


OBJLoader::~OBJLoader()
{
}

bool OBJLoader::load(const char * path, std::vector < glm::vec3 > & out_vertices, std::vector < glm::vec2 > & out_uvs, std::vector < glm::vec3 > & out_normals) {
	FILE * file;
	fopen_s(&file, path, "r");
	if (file == NULL){
		printf("Impossible to open the file !\n");
		return false;
	}
	while (1){

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		// else : parse lineHeader

		if (strcmp(lineHeader, "v") == 0){
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			m_temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0){
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			m_temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0){
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			m_temp_normals.push_back(normal);

		}
		else if (strcmp(lineHeader, "f") == 0){
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9){
				printf("File can't be read by our simple parser :( Try exporting with other options\n");
				return false;
			}
			m_vertexIndices.push_back(vertexIndex[0]);
			m_vertexIndices.push_back(vertexIndex[1]);
			m_vertexIndices.push_back(vertexIndex[2]);
			m_uvIndices.push_back(uvIndex[0]);
			m_uvIndices.push_back(uvIndex[1]);
			m_uvIndices.push_back(uvIndex[2]);
			m_normalIndices.push_back(normalIndex[0]);
			m_normalIndices.push_back(normalIndex[1]);
			m_normalIndices.push_back(normalIndex[2]);

			for (unsigned int i = 0; i < m_vertexIndices.size(); i++){
				unsigned int vertexIndex = m_vertexIndices[i];
				glm::vec3 vertex = m_temp_vertices[vertexIndex - 1];
				out_vertices.push_back(vertex);
			}

			for (unsigned int i = 0; i < m_uvIndices.size(); i++){
				unsigned int uvIndex = m_uvIndices[i];
				glm::vec2 uv = m_temp_uvs[uvIndex - 1];
				out_uvs.push_back(uv);
			}

			for (unsigned int i = 0; i < m_normalIndices.size(); i++){
				unsigned int normalIndex = m_normalIndices[i];
				glm::vec3 normal = m_temp_normals[normalIndex - 1];
				out_normals.push_back(normal);
			}

		}
	}
}