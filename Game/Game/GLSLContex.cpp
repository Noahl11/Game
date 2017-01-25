#include "GLSLContex.h"


GLSLContex::GLSLContex() : m_numAtrtibs(0), m_programID(0), m_vertexShaderID(0), m_fragmentShaderID(0)
{
}


GLSLContex::~GLSLContex()
{
}

void GLSLContex::compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath) {
	m_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (m_vertexShaderID == 0) {
		//Error Text
	}

	m_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (m_fragmentShaderID == 0) {
		//Error Text
	}

	compileShader(vertexShaderFilePath, m_vertexShaderID);
	compileShader(fragmentShaderFilePath, m_fragmentShaderID);
}

void GLSLContex::linkShaders() {
	m_programID = glCreateProgram();

	glAttachShader(m_programID, m_vertexShaderID);
	glAttachShader(m_programID, m_fragmentShaderID);

	glLinkProgram(m_programID);

	GLint isLinked = 0;
	glGetProgramiv(m_programID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &maxLength);
	}
}