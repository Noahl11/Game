#version 330

in vec3 vertexPosition;

out vec4 fragmentColor;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

void main() {
	gl_Position = transformationMatrix * vec4(vertexPosition, 1.0);
	
	vec4 vertexColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	
	fragmentColor = vertexColor;
}