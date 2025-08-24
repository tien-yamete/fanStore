#include "objects/table.h"



void drawTable(vec3 position, vec3 rotation, vec3 scale)
{
	color color1 = color(0.9, 0.9, 0.9, 1);
	color color2 = color(0.1, 0.1, 0.1, 1);
	color color3 = color(0.5, 0.5, 0.5, 1);

	mat4 globalTransformMatrix = cubeTransform(position, rotation, scale);

	drawCube(vec3(0, 0, 0), vec3(), vec3(1.1, .05, .6), color2);

	drawCube(vec3(0, -0.25, -0.2), vec3(), vec3(.95, .5, .05), color1);
	drawCube(vec3(-0.45, -0.25, 0), vec3(), vec3(.05, .5, .45), color1);
	drawCube(vec3(0.45, -0.25, 0), vec3(), vec3(.05, .5, .45), color1);

	drawCube(vec3(.47, -0.25, .22), vec3(), vec3(.05, .5, .05), color(0.36, 0.25, 0.20, 1));
	drawCube(vec3(-.47, -0.25, .22), vec3(), vec3(.05, .5, .05), color(0.36, 0.25, 0.20, 1));
	drawCube(vec3(.47, -0.25, -.22), vec3(), vec3(.05, .5, .05), color(0.36, 0.25, 0.20, 1));
	drawCube(vec3(-.47, -0.25, -.22), vec3(), vec3(.05, .5, .05), color(0.36, 0.25, 0.20, 1));

	drawCube(vec3(0, -0.2, -0.23), vec3(), vec3(1, .05, .05), color2);
	drawCube(vec3(0.48, -0.2, -0.0025), vec3(), vec3(.05, .05, .505), color2);
	drawCube(vec3(-0.48, -0.2, -0.0025), vec3(), vec3(.05, .05, .505), color2);

	drawCube(vec3(0, -0.5, -0.23), vec3(), vec3(1, .05, .05), color2);
	drawCube(vec3(0.48, -0.5, -0.0025), vec3(), vec3(.05, .05, .505), color2);
	drawCube(vec3(-0.48, -0.5, -0.0025), vec3(), vec3(.05, .05, .505), color2);
}
