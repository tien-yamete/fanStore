#include "objects/ceilingFan.h"

vec3 ceilingFan_rotate;

void drawCeilingFan(vec3 position, vec3 rotation, vec3 scale, bool enableInput)
{
	color bodyColor = WHITE;
	if (enableInput)
		rotation += ceilingFan_rotate;
	mat4 globalTransformMatrix = cylinderTransform(position, rotation, scale);
	plane2Transform(position, rotation, scale);

	drawCylinder(vec3(0, 0, 0), vec3(0, 0, 0), vec3(2, .7, 2), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(0,-.8, 0), vec3(0, 0, 0), vec3(.6, 1, .6), color(0.33, 0.27, 0.93, 1));

	drawSphere(vec3(0, -8, 0), vec3(0, 0, 0), vec3(7, 4, 7), color(0.33, 0.27, 0.93, 1));

}

void ceilingFanKeyboard(unsigned char key, int mouseX, int mouseY)
{
	switch (key)
	{
	case 'q':
		ceilingFan_rotate.y += 5;
		break;
	case 'e':
		ceilingFan_rotate.y -= 5;
		break;
	default:
		break;
	}
}
