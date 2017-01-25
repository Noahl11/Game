#pragma once
#include <string>

#include <GL\glew.h>

class GLSLContex
{
public:
	GLSLContex();
	~GLSLContex();

	void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);

	void linkShaders();

	void addAttribute(const std::string& atribName);

	GLint getUniformLocation(const std::string& uniformName);

	void use();
	void unuse();

private:
	void compileShader(const std::string& filePath, GLuint id);

	int m_numAtrtibs;

	GLuint m_programID;
	GLuint m_vertexShaderID;
	GLuint m_fragmentShaderID;
};