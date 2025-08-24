#include "objects/fanStore.h"

void drawFanStore(vec3 position, vec3 rotation, vec3 scale)
{
    mat4 globalTransformMatrix = cubeTransform(position, rotation, scale);
    cylinderTransform(position, rotation, scale);

    color frameColor = color(0.5, 0.5, 0.5, 1);
    color frameColor1 = color(0.4, 0.4, 0.4, 1); 
    color frameColor2 = color(0.9, 0.9, 0.9, 1); 
    color shelfColor = color(0.85, 0.7, 0.5, 1); 
    color color1 = color(0.1, 0.1, 0.1, 1);
    color color2 = color(0.2, 0.2, 0.2, 1);
    color wallColor = color(0, 255, 255, 255) / 255.0f;
    color color4 = color(0.85, 0.75, 0.6, 1);
    color red = color(1, 0 , 0, 1);

    //nen
    drawCylinder(vec3(21, 2, 10), vec3(0, 0, 0), vec3(15, .1, 15), color2);

    drawCylinder(vec3(-2, 4, 15), vec3(0, 0, 0), vec3(20, 4, 12), color2);
    drawCylinder(vec3(-2, 6, 15), vec3(0, 0, 0), vec3(21.5, 1, 13.5), frameColor2);

    drawCube(vec3(0, 1.78, 0), vec3(0, 0, 0), vec3(65, .5, 45), color4);
    drawCube(vec3(0, 0, 0), vec3(0, 0, 0), vec3(70, 4, 50), frameColor);
    drawCube(vec3(0, 40.5, 0), vec3(0, 0, 0), vec3(72, 1.5, 52), frameColor);
    drawCube(vec3(0, 48, 0), vec3(0, 0, 0), vec3(70, 15, 50), frameColor1);
    drawCube(vec3(0, 55, 0), vec3(0, 0, 0), vec3(72, 1.5, 52), frameColor);

    drawCube(vec3(-33, 20, 0), vec3(0, 0, 0), vec3(2, 40, 48), wallColor);
    drawCube(vec3(33, 20, 0), vec3(0, 0, 0), vec3(2, 40, 48), wallColor);
    drawCube(vec3(0, 20, -23), vec3(0, 0, 0), vec3(68, 40, 2), wallColor);

    drawCube(vec3(-33, 5, -23), vec3(0, 0, 0), vec3(3, 8, 3), color1);
    drawCube(vec3(-33, 5, 23), vec3(0, 0, 0), vec3(3, 8, 3), color1);
    drawCube(vec3(33, 5, -23), vec3(0, 0, 0), vec3(3, 8, 3), color1);

    drawCube(vec3(-33, 8, 0), vec3(0, 0, 0), vec3(2.8, 2, 48), color1);
    drawCube(vec3(33, 8, 0), vec3(0, 0, 0), vec3(2.8, 2, 48), color1);
    drawCube(vec3(-33, 5, 0), vec3(0, 0, 0), vec3(2.8, 6, 48), color2);
    drawCube(vec3(33, 5, 0), vec3(0, 0, 0), vec3(2.8, 6, 48), color2);

    drawCube(vec3(0, 8, -23), vec3(0, 0, 0), vec3(68, 2, 2.8), color1);
    drawCube(vec3(0, 5, -23), vec3(0, 0, 0), vec3(68, 6, 2.4), color2);

    //khung cua kinh
    drawCube(vec3(-10, 3, 23), vec3(0, 0, 0), vec3(48, 2, 2), color1);

    drawCube(vec3(30, 3, 23), vec3(0, 0, 0), vec3(5, 2, 2), color1);

    drawCube(vec3(23, 35, 23), vec3(0, 0, 0), vec3(20, 2, 1.95), color1);

    drawCube(vec3(33, 5, 23), vec3(0, 0, 0), vec3(3, 8, 3), color1);

    drawCube(vec3(14, 20, 23), vec3(0, 0, 0), vec3(2, 40, 2), color1);

    drawCube(vec3(-8, 20, 23), vec3(0, 0, 0), vec3(2, 40, 2), color1);

    drawCube(vec3(28, 18, 23), vec3(0, 0, 0), vec3(2, 35, 2), color1);

    drawCube(vec3(33, 3, 0), vec3(0, 0, 0), vec3(2, 2, 48), color1);

    //bac thang
    drawCube(vec3(21, 1, 26), vec3(0, 0, 0), vec3(20, 2, 2), frameColor1);
    drawCube(vec3(21, -.5, 27), vec3(0, 0, 0), vec3(20, 2, 5), frameColor1);

    //duong
    drawCube(vec3(0, -2, 0), vec3(0, 0, 0), vec3(100, 1, 100), frameColor);

    //kinh
    drawCube(vec3(3, 15, 23), vec3(0, 0, 45), vec3(10, 2, .01), WHITE);
    drawCube(vec3(3, 25, 23), vec3(0, 0, 45), vec3(10, 2, .01), WHITE);

    drawCube(vec3(-20, 15, 23), vec3(0, 0, 45), vec3(10, 2, .01), WHITE);
    drawCube(vec3(-20, 25, 23), vec3(0, 0, 45), vec3(10, 2, .01), WHITE);

    //drawCube(vec3(33, 15, 10), vec3(45, 0, 0), vec3(.01, 2, 10), WHITE);
    //drawCube(vec3(33, 25, 10), vec3(45, 0, 0), vec3(.01, 2, 10), WHITE);

    //drawCube(vec3(33, 15, -10), vec3(45, 0, 0), vec3(.01, 2, 10), WHITE);
    //drawCube(vec3(33, 25, -10), vec3(45, 0, 0), vec3(.01, 2, 10), WHITE);
}