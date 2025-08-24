#include "objects/portableFan.h"

int dir = 1;
float fanRotAxis = 0;
float bladeRotation = 0;



void drawPortableFan(vec3 position, vec3 rotation, vec3 scale, bool enableInput)
{
    bladeRotation += 1;
    fanRotAxis += .15f * dir;
    if(fanRotAxis > 30)
    {
        dir = -1;
    }
    if(fanRotAxis < -30)
    {
        dir = 1;
    }
    
    mat4 globalTransformMatrix = cubeTransform(position, rotation, scale);

    // 1. Đế
    drawCube(vec3(0, -1, 0), vec3(0), vec3(1.5f, 0.2f, 1.5f), color3(0.2f, 0.8f, 0.2f));

    // tru
    drawCube(vec3(0, 0, 0), vec3(0), vec3(0.2f, 1.5f, 0.2f), color3(0.2f, 0.8f, 0.2f));

    // than
    drawCube(vec3(0, 1.0f, 0), vec3(0), vec3(0.5f, 0.3f, 0.5f), color3(0.2f, 0.8f, 0.2f));

    //motor
    auto mat1 = cubeTransformMatrix(globalTransformMatrix * Angel::RotateY(fanRotAxis));
    
    drawCube(vec3(0, 1.0f, -.5f), vec3(0), vec3(1, 1, 1), color3(0.2f, 0.8f, 0.2f));
    drawCube(vec3(0, 1.0f, -1.1f), vec3(0), vec3(.24f, .24f, .75f), color3(0.2f, 0.8f, 0.2f));

    
    
     auto matrix = cubeTransformMatrix(mat1 * Angel::Translate(0, 1.0f, -1.25f) * Angel::RotateX(90)
         * Angel::RotateY(bladeRotation));

    
    // 4. Cánh quạt
    int seg = 3;
    for (int i = 0; i < seg; i++) {
        vec3 bladeRot = vec3(0, i * (360 / seg), 0);          // xoay quanh Y, mỗi cánh cách 90°
        vec3 bladePos = vec3(0, 0, 0);

        drawCube(bladePos, bladeRot, vec3(0.3f, .1f, 2), color3(0.7f, 0.7f, 0.7f));
    }
    
    cubeReset();
}

void portableFan_onLoop()
{
    bladeRotation += 0.1f;
}

void portableFanKeyboard(unsigned char key, int mouseX, int mouseY)
{
    
}
