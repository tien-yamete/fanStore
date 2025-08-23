#pragma once
#include "core/openGL.h"

#include "cube.h"
#include "cylinder.h"
#include "plane.h"
#include "plane2.h"
#include "sphere.h"

void drawFan1(vec3 position, vec3 rotation, vec3 scale, bool enableInput = false);

void fan1Keyboard(unsigned char key, int mouseX, int mouseY);
