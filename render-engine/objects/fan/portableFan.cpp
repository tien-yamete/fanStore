#include "objects/portableFan.h"

void drawPortableFan(vec3 position, vec3 rotation, vec3 scale, bool enableInput)
{
    mat4 globalTransformMatrix = cubeTransform(position, rotation, scale);

    // 1. Đế
    drawCube(vec3(0, -1, 0), vec3(0), vec3(2, 0.2f, 2), color3(0.2f, 0.8f, 0.2f));

    // 2. Trụ
    drawCube(vec3(0, 0, 0), vec3(0), vec3(0.2f, 1.5f, 0.2f), color3(0.2f, 0.8f, 0.2f));

    // 3. Thân/khớp
    drawCube(vec3(0, 1.2f, 0), vec3(0), vec3(0.5f, 0.3f, 0.5f), color3(0.2f, 0.8f, 0.2f));

    // 4. Cánh quạt
    for (int i = 0; i < 4; i++) {
        vec3 bladeRot = vec3(0, i * 90.0f, 0);          // xoay quanh Y, mỗi cánh cách 90°
        vec3 bladePos = vec3(0, 1.2f, 0.5f);            // gốc cánh
        drawCube(bladePos, bladeRot, vec3(0.1f, 0.6f, 0.2f), color3(0.7f, 0.7f, 0.7f));
    }

    // 5. Khung bảo vệ (giả vòng tròn bằng nhiều cube nhỏ)
    int segments = 16;
    float radius = 1.0f;
    for (int i = 0; i < segments; i++) {
        float angle = i * (360.0f / segments);
        float x = cos(angle * M_PI / 180.0f) * radius;
        float z = sin(angle * M_PI / 180.0f) * radius;
        drawCube(vec3(x, 1.2f, z), vec3(0), vec3(0.05f, 0.05f, 0.2f), color3(0, 0.5f, 0.5f));
    }

    cubeReset();
}

void portableFanKeyboard(unsigned char key, int mouseX, int mouseY)
{
    
}
