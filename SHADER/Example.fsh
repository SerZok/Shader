#version 330 core

uniform vec4 color1;
uniform vec4 color2;
uniform vec4 color3;

in vec2 position;

out vec4 fragColor;

void main ()
{
	if(position.y<=-0.165){
		fragColor=color1;
	}
	else if(position.y>-0.165 && position.y<0.165){
		fragColor=color2;
	}
	else {
		fragColor=color3;
	}

}
