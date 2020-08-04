#version 150

// these are for the programmable pipeline system
uniform mat4 modelViewProjectionMatrix;
in vec4 position;

uniform float mouseRange;
uniform vec2 mousePos;
uniform vec4 mouseColor;

in vec2 texcoord;

uniform float u_time;

out vec2 texCoordVaring;

void main() {

	texCoordVaring = texcoord;

    vec4 pos = position;
	vec2 dir = pos.xy - vec2(sin(u_time * 1.0) * 0.0, 0.0);
    
    if (pos.x>300.0) {
    	dir = pos.xy - vec2(sin(u_time * 1.0) * 0.0, 0.0);	
    }

	pos.x += dir.x;
	pos.y += dir.y;

	mat4 _m = mat4(
		0.0, 0.0, 0.0, 0.0, 
		0.0, 0.50, 0.0, 0.0, 
		0.0, 0.0, 0.50, 0.0, 
		0.0, 0.0, 0.0, 1.0);

	gl_Position = modelViewProjectionMatrix * position;
}