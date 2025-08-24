#include "objects/fan1.h"

vec3 fan1_rotate;

static bool cf_on = false;
static bool cd_on = false;

static float cf_angle = 0.0f;
static float cd_angle = 0.0f;
static float cd_dir = 1.0f;

void drawFan1(vec3 position, vec3 rotation, vec3 scale, bool enableInput)
{
    color color1 = color(.15, .15, .15, 1);
    color color2 = color(1, 0.5, 0, 1);
    color wood = color(0.5f, 0.35f, 0.05f, 1.0f);

    if (enableInput) rotation += fan1_rotate;

    if (cf_on) {
        cf_angle += 1.0f;
        if (cf_angle >= 360.0f) cf_angle -= 360.0f;
    }

    if (cd_on) {
        cd_angle += cd_dir * 0.6f;
        if (cd_angle > 25.0f) { cd_angle = 25.0f;  cd_dir = -1.0f; }
        if (cd_angle < -25.0f) { cd_angle = -25.0f; cd_dir = 1.0f; }
    }

    mat4 globalTransformMatrix = cubeTransform(position, rotation, scale);
    cylinderTransform(position, rotation, scale);
    plane2Transform(position, rotation, scale);

    cubeTransformMatrix(globalTransformMatrix);
    drawCylinder(vec3(0, 0, 0), vec3(0), vec3(3, .4, 3), color1);
    drawCylinder(vec3(0, 2, 0), vec3(0), vec3(.6, 4, .6), color1);
    drawCylinder(vec3(0, 4, 0), vec3(0), vec3(1, .5, 1), color1);
    drawPlane2(vec3(0, 4.55, 0), vec3(90, 0, 0), vec3(.85, .7, .85), color1);
    drawCube(vec3(0, -2.75, 0), vec3(0), vec3(.2, .5, .2), color1);
    drawCube(vec3(-.1, -2.45, 0), vec3(0, 0, 30), vec3(.1, .2, .1), color1);

    mat4 headBase = globalTransformMatrix;

    vec3 pivotHead = vec3(-1.35f, 9.0f, 0.0f);
    vec3 pivotBlade = vec3(-3.2f, 9.0f, 0.0f);

    mat4 headYaw = Angel::Translate(pivotHead) * Angel::RotateY(cd_angle) * Angel::Translate(-pivotHead);
    mat4 bladeSpin = Angel::Translate(pivotBlade) * Angel::RotateX(cf_angle) * Angel::Translate(-pivotBlade);

    cylinderTransformMatrix(headBase * headYaw);
    drawCylinder(vec3(.5, 9, 0), vec3(0, 0, 90), vec3(2, 1.5, 2), color1);
    drawCylinder(vec3(-1.2, 9, 0), vec3(0, 0, 90), vec3(2.4, 2, 2.4), color1);
    drawCylinder(vec3(-2.2, 9, 0), vec3(0, 0, 90), vec3(1, .4, 1), wood);
    drawCylinder(vec3(-2.7, 9, 0), vec3(0, 0, 90), vec3(.3, .5, .3), wood);
    drawCylinder(vec3(-3.2, 9, 0), vec3(0, 0, 90), vec3(1.2, .5, 1.2), wood);

    plane2TransformMatrix(headBase * headYaw * bladeSpin);
    drawPlane2(vec3(-3.2, 9, 2), vec3(0, 0, 90), vec3(2, .15, 4), color2);
    drawPlane2(vec3(-3.2, 9, -2), vec3(180, 0, 90), vec3(1.5, .15, 4), color2);
    drawPlane2(vec3(-3.2, 7, 0), vec3(90, 0, 90), vec3(1.5, .15, 4), color2);
    drawPlane2(vec3(-3.2, 11, 0), vec3(-90, 0, 90), vec3(1.5, .15, 4), color2);

    plane2TransformMatrix(globalTransformMatrix);
    cubeReset();
}

void fan1Keyboard(unsigned char key, int mouseX, int mouseY)
{
    switch (key)
    {
    case 'q': cd_on = true;  break;
    case 'e': cd_on = false; break;
    case 'b': cf_on = true;  break;
    case 't': cf_on = false; break;
    default: break;
    }
}
