#include "objects/fan1.h"

vec3 fan1_rotate;

static void drawFanBlade1(color col, mat4 matrix)
{
    plane2TransformMatrix(matrix);
    drawPlane2(vec3(0, 0, 0.9), vec3(0, 0, 0), vec3(.20, .06, 1.8), col);
    plane2Reset();

    cylinderTransformMatrix(matrix);
    drawCylinder(vec3(0, 0, 1.85), vec3(90, 0, 0), vec3(.09, .09, .09), col);
    cylinderReset();
}

static void drawFanHead1(color headColor, mat4 matrix)
{
    cylinderTransformMatrix(matrix);
    drawCylinder(vec3(0, 0, 0), vec3(90, 0, 0), vec3(0.95, 0.95, 0.95), headColor);
    drawCylinder(vec3(0, 0, 0.55), vec3(90, 0, 0), vec3(0.12, 0.20, 0.12), color(0.92, 0.77, 0.59, 1));
    drawCylinder(vec3(0, 0, 0.68), vec3(90, 0, 0), vec3(0.22, 0.10, 0.22), color(0.33, 0.27, 0.93, 1));
    cylinderReset();

    mat4 base = plane2TransformMatrix(matrix * Translate(0, 0, 0.70));
    drawFanBlade1(color(0.20, 0.60, 0.90, 1), base * RotateY(0));
    drawFanBlade1(color(0.20, 0.60, 0.90, 1), base * RotateY(120));
    drawFanBlade1(color(0.20, 0.60, 0.90, 1), base * RotateY(240));
    plane2Reset();

    cylinderTransformMatrix(matrix);
    drawCylinder(vec3(0, 0, 0.82), vec3(90, 0, 0), vec3(0.85, 0.02, 0.85), color(0.33, 0.27, 0.93, 1));
    drawCylinder(vec3(0, 0, 0.86), vec3(90, 0, 0), vec3(0.95, 0.02, 0.95), color(0.33, 0.27, 0.93, 1));
    for (int i = 0; i < 6; ++i) {
        float a = i * 60.0f;
        drawCylinder(vec3(0, 0, 0.84), vec3(0, 0, a), vec3(.02, 1.6, .02), color(0.91, 0.36, 0.39, 1));
    }
    cylinderReset();
}

void drawFan1(vec3 position, vec3 rotation, vec3 scale, bool enableInput)
{
    if (enableInput) rotation += fan1_rotate;

    mat4 globalTransformMatrix = cylinderTransform(position, rotation, scale);
    plane2Transform(position, rotation, scale);

    drawCylinder(vec3(0, -1.6, 0), vec3(90, 0, 0), vec3(1.4, .30, 1.4), color(0.33, 0.27, 0.93, 1));
    drawCylinder(vec3(0, -1.45, 0), vec3(90, 0, 0), vec3(1.1, .12, 1.1), color(0.92, 0.77, 0.59, 1));
    drawCylinder(vec3(0, -0.3, 0), vec3(90, 0, 0), vec3(.22, 1.9, .22), color(0.33, 0.27, 0.93, 1));
    drawCylinder(vec3(0, 0.8, 0), vec3(0, 0, 0), vec3(.28, .28, .28), color(0.92, 0.77, 0.59, 1));

    drawFanHead1(color(0.33, 0.27, 0.93, 1), globalTransformMatrix * Translate(0, 1.05, 0));

    cylinderReset();
    plane2Reset();
    planeReset();
}

void fan1Keyboard(unsigned char key, int mouseX, int mouseY)
{
    switch (key)
    {
    case 'q': fan1_rotate.y += 5; break;
    case 'e': fan1_rotate.y -= 5; break;
    default: break;
    }
}
