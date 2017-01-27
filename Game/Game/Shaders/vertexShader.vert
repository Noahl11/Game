#version 330

in vec2 vertexPosition;

out vec4 fragmentColor;

void main() {
	gl_Position.xy = vertexPosition;
	gl_Position.z = 0.0f;
	gl_Position.w = 1.0f;
	
	vec4 vertexColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	
	fragmentColor = vertexColor;
}