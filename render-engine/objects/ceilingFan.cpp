#include "objects/ceilingFan.h"

vec3 ceilingFan_rotate;

static bool cf_on = false;
static float cf_angle = 0.0f;

void drawCeilingFan(vec3 position, vec3 rotation, vec3 scale, bool enableInput)
{
    if (enableInput)
        rotation += ceilingFan_rotate;

    if (cf_on) {
        cf_angle += 1.0f;
        if (cf_angle >= 360.0f) cf_angle -= 360.0f;
    }

    mat4 globalTransformMatrix = cylinderTransform(position, rotation, scale);
    plane2Transform(position, rotation, scale);

    drawCylinder(vec3(0, 0, 0), vec3(0, 0, 0), vec3(2, .7, 2), color(1, 1, 1, 1));

    mat4 currentModelMatrix = cubeTransformMatrix(globalTransformMatrix * (enableInput ? Angel::RotateY(ceilingFan_rotate.y) : identity()));

    drawCylinder(vec3(0, -.8, 0), vec3(0, 0, 0), vec3(.6, 1, .6), color(1, 1, 1, 1));
    drawCylinder(vec3(0, -1.5, 0), vec3(0, 0, 0), vec3(2, 1, 2), color(1, 1, 1, 1));

    plane2TransformMatrix(globalTransformMatrix * Angel::RotateY(cf_angle));
    drawPlane2(vec3(0, -1.5, 4), vec3(0, 0, 0), vec3(2, .3, 8), color(1, 1, 1, 1));
    drawPlane2(vec3(-4, -1.5, -2.3), vec3(0, -120, 0), vec3(2, .3, 8), color(1, 1, 1, 1));
    drawPlane2(vec3(4, -1.5, -2.3), vec3(0, 120, 0), vec3(2, .3, 8), color(1, 1, 1, 1));
    plane2TransformMatrix(globalTransformMatrix);
}

void ceilingFanKeyboard(unsigned char key, int mouseX, int mouseY)
{
    switch (key)
    {
    case 'm':
        cf_on = true;
        break;
    case 'n':
        cf_on = false;
        break;
    default:
        break;
    }
}
