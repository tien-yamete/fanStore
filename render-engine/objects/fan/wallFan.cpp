#include "objects/wallFan.h"

float w_motor_rot = 0;
float w_blade_rot = 0;
float w_dir = 1;

void drawWallFan(vec3 position, vec3 rotation, vec3 scale, bool enableInput)
{
    w_blade_rot += 2;

    w_motor_rot += 0.1f * w_dir;
    if(w_motor_rot > 30 )
    {
        w_dir = -1;
    }

    if(w_motor_rot < -30 )
    {
        w_dir = 1;
    }
    
    
    color c = color3(1, 1, 0);
    
    mat4 globalTransformMatrix = cubeTransform(position, rotation, scale);

    // 1. Đế
    drawCube(vec3(0, 1, 0), vec3(0), vec3(1.75f, 2.5f, .15f), c);
    drawCube(vec3(0, 1.5f, 0.15f), vec3(0), vec3(1.0f, 1.5f, .15f), c);

    // tru
    drawCube(vec3(0, 1.5f, .75f), vec3(0), vec3(.74f, .74f, 1.5f), c);
    drawCube(vec3(0, 1.9f, 1.85f), vec3(-40, 0, 0), vec3(.74f, .74f, 1.5f), c);

    // motor
    vec3 pivot = vec3(0, 3.0f, 2.85f);
    auto matrix = cubeTransformMatrix(globalTransformMatrix
        * Angel::Translate(pivot)
        * Angel::RotateY(w_motor_rot)
        * Angel::Translate(-pivot));
    
    drawCube(vec3(0, 3.0f, 2.85f), vec3(40, 0, 0), vec3(2.0f, 2.0f, 3.5f), c);
    drawCube(vec3(0, 2.75f, 3.25f), vec3(40, 0, 0), vec3(.75f, .75f, 3.95f), c);

    // canh
    auto matrix2 = cubeTransformMatrix(matrix
        * Angel::Translate(0, 1.5f, 4.85f)
        * Angel::RotateX(-50)
        * Angel::RotateY(w_blade_rot));
    
    // 4. Cánh quạt
    int seg = 3;
    for (int i = 0; i < seg; i++) {
        vec3 bladeRot = vec3(0, i * (360 / seg), 0);          
        vec3 bladePos = vec3(0, 0, 0);

        drawCube(bladePos, bladeRot, vec3(0.3f, .1f, 4.0f), color3(0.7f, 0.7f, 0.7f));
    }
    
    
    cubeReset();
}


