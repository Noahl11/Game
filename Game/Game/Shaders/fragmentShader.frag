#version 430

in vec4 fragmentColor;

out vec4 color;

uniform float time;

void main() {
	color = fragmentColor + vec4(1.0f * (cos(time)+1.0f) *0.5, 
								1.0f * (cos(time)+2.0f) *0.5, 
								1.0f * (sin(time)+1.0f) *0.5,
								1.0f);
}