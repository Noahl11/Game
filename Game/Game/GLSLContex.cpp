#include "GLSLContex.h"
#include <vector>
#include <fstream>

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

		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(m_programID, maxLength, &maxLength, &errorLog[0]);

		glDeleteProgram(m_programID);

		glDeleteShader(m_vertexShaderID);
		glDeleteShader(m_fragmentShaderID);

		std::printf("%\n", &(errorLog[0]));
		//Error Text
	}

	glDetachShader(m_programID, m_vertexShaderID);;
	glDetachShader(m_programID, m_fragmentShaderID);
	glDeleteShader(m_vertexShaderID);
	glDeleteShader(m_fragmentShaderID);

}

void GLSLContex::addAttribute(const std::string& atribName) {
	glBindAttribLocation(m_programID, m_numAtrtibs++, atribName.c_str());
}

GLint GLSLContex::getUniformLocation(const std::string& uniformName) {
	GLint location = glGetUniformLocation(m_programID, uniformName.c_str());
	if (location == GL_INVALID_INDEX) {
		//Error Text
	}
	return location;
}

void GLSLContex::use() {
	glUseProgram(m_programID);
	for (int i = 0; i < m_numAtrtibs; i++) {
		glEnableVertexAttribArray(i);
	}
}

void GLSLContex::unuse() {
	glUseProgram(0);
	for (int i = 0; i < m_numAtrtibs; i++) {
		glDisableVertexAttribArray(i);
	}
}

void GLSLContex::compileShader(const std::string& filePath,  GLuint id) {
	std::ifstream vertexFile(filePath);
	if (vertexFile.fail()) {
		perror(filePath.c_str());
		//Error Text
	}

	std::string fileContents = "";
	std::string line;

	while (std::getline(vertexFile, line)) {
		fileContents += line + "\n";
	}

	vertexFile.close();
	const char* constentPtr = fileContents.c_str();

	glShaderSource(id, 1, &constentPtr, nullptr);
	glCompileShader(id);

	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		glDeleteShader(id);

		std::printf("%s\n", &(errorLog[0]));
	}
}