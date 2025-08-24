#include "objects/fan1.h"

vec3 fan1_rotate;

// cau hinh de chinh
static const float CF_SPEED_DEG = 1.9f;   // toc do quay canh do moi frame khi bat
static const float CD_SPEED_DEG = 0.12f;   // toc do lac dau do moi frame
static const float CD_MAX_SWEEP = 60.0f;  // bien do lac dau � do tang giam de quet rong hep

static bool cf_on = false;
static bool cd_on = false;

static float cf_angle = 0.0f;   // goc quay canh
static float cd_angle = 0.0f;   // goc lac dau hien tai
static float cd_dir = 1.0f;   // huong lac 1 sang phai  -1 sang trai

void drawFan1(vec3 position, vec3 rotation, vec3 scale, bool enableInput)
{
    color color1 = color(.15, .15, .15, 1);
    color color2 = color(1, 0.5, 0, 1);
    color wood = color(0.5f, 0.35f, 0.05f, 1.0f);

    if (enableInput) rotation += fan1_rotate;

    // cap nhat quay canh
    if (cf_on) {
        cf_angle += CF_SPEED_DEG;
        if (cf_angle >= 360.0f) cf_angle -= 360.0f;
    }

    // cap nhat lac dau quet rong hon nho CD_MAX_SWEEP lon
    if (cd_on) {
        cd_angle += cd_dir * CD_SPEED_DEG;
        if (cd_angle > CD_MAX_SWEEP) { cd_angle = CD_MAX_SWEEP; cd_dir = -1.0f; }
        if (cd_angle < -CD_MAX_SWEEP) { cd_angle = -CD_MAX_SWEEP; cd_dir = 1.0f; }
    }

    // transform goc
    mat4 globalTransformMatrix = cylinderTransform(position, rotation, scale);
    plane2Transform(position, rotation, scale);
    cubeTransform(position, rotation, scale);

    // chan tru
    //cubeTransformMatrix(globalTransformMatrix);
    drawCylinder(vec3(0, 0, 0), vec3(0), vec3(3, .4, 3), color1);
    drawCylinder(vec3(0, 2, 0), vec3(0), vec3(.6, 4, .6), color1);
    drawCylinder(vec3(0, 4, 0), vec3(0), vec3(1, .5, 1), color1);
    drawPlane2(vec3(0, 4.55, 0), vec3(90, 0, 0), vec3(.85, .7, .85), color1);
    drawCube(vec3(0, -2.75, 0), vec3(0), vec3(.2, .5, .2), color1);
    drawCube(vec3(-.1, -2.45, 0), vec3(0, 0, 30), vec3(.1, .2, .1), color1);

    // cac pivot
    mat4 headBase = globalTransformMatrix;

    // tam quay dau quat dat o giua cum dau quat ngay khop noi khong dat o canh
    const vec3 pivotHead = vec3(-0.0f, 6.0f, 0.0f);
    // tam quay canh ngay bau canh hub
    const vec3 pivotBlade = vec3(-3.2f, 6.0f, 0.0f);

    // yaw lac trai phai quanh pivotHead
    mat4 headYaw = Angel::Translate(pivotHead) * Angel::RotateY(cd_angle) * Angel::Translate(-pivotHead);
    // spin canh quanh truc X tai pivotBlade
    mat4 bladeSpin = Angel::Translate(pivotBlade) * Angel::RotateX(cf_angle) * Angel::Translate(-pivotBlade);

    // ve than dau quat theo headYaw
    cylinderTransformMatrix(headBase * headYaw);
    drawCylinder(vec3(.5f, 6.0f, 0), vec3(0, 0, 90), vec3(2, 1.5, 2), color1);
    drawCylinder(vec3(-1.2f, 6.0f, 0), vec3(0, 0, 90), vec3(2.4, 2, 2.4), color1);
    drawCylinder(vec3(-2.2f, 6.0f, 0), vec3(0, 0, 90), vec3(1, .4, 1), wood);
    drawCylinder(vec3(-2.7f, 6.0f, 0), vec3(0, 0, 90), vec3(.3, .5, .3), wood);
    drawCylinder(vec3(-3.2f, 6.0f, 0), vec3(0, 0, 90), vec3(1.2, .5, 1.2), wood);

    // ve canh theo headYaw * bladeSpin tuc la lac dau + quay canh
    plane2TransformMatrix(headBase * headYaw * bladeSpin);
    drawPlane2(vec3(-3.2f, 6.0f, 2), vec3(0, 0, 90), vec3(2, .15, 4), color2);
    drawPlane2(vec3(-3.2f, 6.0f, -2), vec3(180, 0, 90), vec3(1.5, .15, 4), color2);
    drawPlane2(vec3(-3.2f, 4.0f, 0), vec3(90, 0, 90), vec3(1.5, .15, 4), color2);
    drawPlane2(vec3(-3.2f, 8.0f, 0), vec3(-90, 0, 90), vec3(1.5, .15, 4), color2);
    // reset
    plane2TransformMatrix(globalTransformMatrix);
    cubeReset();
    plane2Reset();
    cylinderReset();
}

void fan1Keyboard(unsigned char key, int mouseX, int mouseY)
{
    switch (key)
    {
    case 'c': cd_on = !cd_on;
        break; // bat lac dau
    case 'v': cf_on = !cf_on;
        break; // tat quay canh
    default: break;
    }
}
