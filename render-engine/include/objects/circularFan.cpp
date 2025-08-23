#include "objects/circularFan.h"

int cdir = 1;
float cfanRotAxis = 0;
float cbladeRotation = 0;

void khung(vec3 pos, color3 color);

void drawCircularFan(vec3 position, vec3 rotation, vec3 scale, bool enableInput)
{
    cbladeRotation += 1;
    mat4 globalTransformMatrix = cubeTransform(position, rotation, scale);

    color3 color = color3(1, 0, 0);
    // 1. Đế
    drawCube(vec3(0, -1.0f, 0), vec3(0), vec3(2, 0.3f, 2), color);
    drawCube(vec3(0, -.77f, -.7f), vec3(0), vec3(.4f, 0.1f, .4f),  color);

    // tru + khung
    drawCube(vec3(0, -.55f, 0), vec3(0), vec3(0.2f, .5f, 0.2f), color);
    drawCube(vec3(0, -.4f, 0), vec3(0), vec3(1.5f, .2f, 0.2f), color);
    
    drawCube(vec3(.95f, .25f, 0), vec3(0, 0, -20), vec3(0.2f, 1.5f, 0.2f), color);
    drawCube(vec3(-.95f, .25f, 0), vec3(0, 0, 20), vec3(0.2f, 1.5f, 0.2f), color);

    
    drawCube(vec3(-1.0f, .95f, 0), vec3(0, 0, 30), vec3(0.5f, .12f, 0.12f), color);
    drawCube(vec3(1.0f, .95f, 0), vec3(0, 0, -30), vec3(0.5f, .12f, 0.12f), color);
    
    //motor
    auto mat1 = cubeTransformMatrix(globalTransformMatrix * Angel::RotateX(cfanRotAxis));
    
    drawCube(vec3(0, 1.2f, -0.0f), vec3(0), vec3(1.0f, 1.0f, 1.0f), color);
    drawCube(vec3(0, 1.2f, -0.0f), vec3(0), vec3(.3f, .1f, .1f), color);

    // khung quat
    khung(vec3(0, 0, 0.85f), color);
    khung(vec3(0, 0, -0.85f), color);

    //khugn doc
    drawCube(vec3(.75f, .5f, 0), vec3(0.0f), vec3(0.05f, .05f, 1.7f), color);
    drawCube(vec3(-.75f, 1.85f, 0), vec3(0.0f), vec3(0.05f, .05f, 1.7f), color);
    drawCube(vec3(-.75f, .5f, 0), vec3(0.0f), vec3(0.05f, .05f, 1.7f), color);
    drawCube(vec3(.75f, 1.85f, 0), vec3(0.0f), vec3(0.05f, .05f, 1.7f), color);

    drawCube(vec3(.75f, 1.0f, 0), vec3(0.0f), vec3(0.05f, .05f, 1.7f), color);
    drawCube(vec3(-.75f, 1.0f, 0), vec3(0.0f), vec3(0.05f, .05f, 1.7f), color);
    
    auto matrix = cubeTransformMatrix(mat1 * Angel::Translate(0, 1.25f, -0.55f) * Angel::RotateX(90)
        * Angel::RotateY(cbladeRotation));
    
    //canh quat
    int seg = 3;
    for (int i = 0; i < seg; i++) {
        vec3 bladeRot = vec3(0, i * (360.0f / seg), 0);    
        vec3 bladePos = vec3(0, 0, 0);
        drawCube(bladePos, bladeRot, vec3(0.2f, .05f, 1.85f), color3(0.7f, 0.7f, 0));
    }
    
    cubeReset();
}

void khung(vec3 pos, color3 color)
{
    drawCube(pos + vec3(0.0f, .5f, -0), vec3(0.0f), vec3(1.8f, 0.05f, 0.05f), color);
    drawCube(pos + vec3(0.0f, 1.8f, 0), vec3(0.0f), vec3(1.8f, 0.05f, 0.05f), color);
    drawCube(pos + vec3(-0.75f, 1.15f, 0), vec3(0.0f), vec3(0.05f, 1.5f, 0.05f), color);
    drawCube(pos + vec3(0.75f, 1.15f, 0), vec3(0.0f), vec3(0.05f, 1.5f, 0.05f), color);
}

void circularFanKeyboard(unsigned char key, int mouseX, int mouseY)
{
    if(key == 'u')
    {
        if(cfanRotAxis > 40)
        {
            return;
        }
        cfanRotAxis += .55f;
    }
    else if(key == 'i')
    {
        if(cfanRotAxis < -40)
        {
            return;
        }
        cfanRotAxis -= .55f;
    }
}
