#pragma warning(disable : 4244)		//disable truncated double to float (currently we dont care about performace :D )

//include core engine

#include <core/openGL.h>		// open gl and utilities
#include <core/camera.h>		// camera
#include <core/shaders.h>		// shaders
#include <core/environment.h>	// environment
#include <core/lighting.h>		// lighting
#include <core/ui.h>			// user interface

//include objects
#include <objects/cube.h>		
#include <objects/plane.h>
#include <objects/plane2.h>
#include <objects/cylinder.h>		
#include <objects/sphere.h>

//scene objects
#include "objects/shelf.h"	
#include "objects/computer.h"	
#include "objects/cabinet.h"	
#include "objects/table.h"	
#include "objects/lamp.h"
#include "objects/chair.h"
#include "objects/chair1.h"
#include "objects/fanStore.h"
#include "objects/keyboard.h"
#include "objects/mouse.h"

#include "objects/fan1.h"
#include "objects/ceilingFan.h"

#include "objects/portableFan.h"
#include "objects/circularFan.h"
#include "objects/wallFan.h"

using namespace engine;
using namespace std;

ui::button btnDay;
ui::button btnNight;
ui::button btnSunset;
ui::button btnAxes;
bool enableAxes = true;

void toggleAxes()
{
	enableAxes = !enableAxes;
}

bool leftMouseButtonDown = false;
int lastMouseX, lastMouseY;

int selectedIndex = -1;

bool disableCamRot = false;


//LIGHTING

directionalLight* sun_light;
pointLight* lamp_light_1;
pointLight* lamp_light_2;
pointLight* lamp_light_3;

void setupLights()
{
	sun_light = oneDirectionalLight(vec3(1, 10, 2), vec3(-.5, -1, -.5));
	sun_light->ambient =
		sun_light->diffuse =
		sun_light->specular = color3(.15f, .15f, .15f);

	lamp_light_1 = addPointLight(vec3());
	lamp_light_1->radius = 100;
	lamp_light_1->ambient = color3(1, 1, 1);
	lamp_light_1->diffuse =
		lamp_light_1->specular = color3(1, 1, 0);

	lamp_light_2 = addPointLight(vec3());
	lamp_light_2->radius = 100;
	lamp_light_2->ambient = color3(1, 1, 1);
	lamp_light_2->diffuse =
		lamp_light_2->specular = color3(0, 1, 1);

	lamp_light_3 = addPointLight(vec3());
	lamp_light_3->radius = 100;
	lamp_light_3->ambient = color3(1, 1, 1);
	lamp_light_3->diffuse =
		lamp_light_3->specular = color3(1, 0, 1);
}

void day()
{
	sun_light->ambient =
		sun_light->diffuse =
		sun_light->specular = color3(.9f, .9f, .9f);
}

void night()
{
	sun_light->ambient =
		sun_light->diffuse =
		sun_light->specular = color3(.1f, .1f, .1f);
}

void sunset()
{
	sun_light->ambient = color3(1, 1, 1);
	sun_light->diffuse =
		sun_light->specular = color3(.8f, .2f, .0f);
}


void initialize_before_display()
{
	engine::initEnvironment();
	engine::initDefaultShaders();
	setupLights();
	initCube();
	initPlane();
	initPlane2();
	initCylinder();
	initSphere();

	setCameraPos(vec4(0, 15, 90, 1));
	setTargetPos(vec4(0, 15, 89, 1));
	rotateCam(180 * 30 * Deg2Rad);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	if (enableAxes) drawAxes();
	
	drawFanStore(vec3(0, 0, 0), vec3(0, 0, 0), vec3(1.5, 1.2, 1.5));

	drawCabinet(vec3(-41, 11, -17), vec3(0, 90, 0), vec3(25, 20, 30));	
	
	drawLamp(vec3(32, 35, 20), vec3(), vec3(5, 5, 5), lamp_light_2);
	
	drawTable(vec3(-42, 7, 16), vec3(0, -90, 0), vec3(32, 20, 20));
	
	drawTable(vec3(33, 13, -17), vec3(0, -180, 0), vec3(25, 20, 20));
	
	drawChair1(vec3(40, 6.5, -25), vec3(0, 0, 0), vec3(8.5, 8, 8.5));
	
	drawComputer(vec3(34.5, 17, -15), vec3(0, 90, 0), vec3(10, 10, 10));
	
	drawKeyboard(vec3(34.5, 13.8, -20), vec3(0, 0, 0), vec3(5, 5, 5));
	
	drawMouse(vec3(27.5, 13.8f, -20), vec3(0, 0, 0), vec3(5, 5, 5));

	// ================DRAW 5 FANS=============================
	drawCeilingFan(vec3(0, 48, 0), vec3(0, 0, 0), vec3(3, 3, 3), true);
	
	drawPortableFan(vec3(-24, 10.5f, -24), vec3(0, -180, 0), vec3(8), false);
	
	drawFan1(vec3(-1, 3.5f, -24), vec3(0, 90, 0), vec3(2.75f), true);
	
	drawCircularFan(vec3(22, 15.5f, -17), vec3(0, -180, 0), vec3(2));

	drawWallFan(vec3(47, 23.5f, -22), vec3(0, -90, 0), vec3(2));
	
	//onGUI();
	
	glutSwapBuffers();
}


void idle()
{
	glutPostRedisplay();
}

void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(20, timer, value++);
}

void input(unsigned char key, int mouseX, int mouseY)
{
	cameraMove(key, mouseX, mouseY);
	circularFanKeyboard(key, mouseX, mouseY);
	fan1Keyboard(key, mouseX, mouseY);
	switch (key)
	{
	case '1':
		
		break;
	case '2':
		
		break;
	case '3':
	
		break;
	case '4':
		
		break;
	case '5':
	
		break;
	case '6':
		
		break;
	case '7':
		
		break;
	case '0':
	{
		engine::setTargetPos(vec4(35.5f, 17.0f, 21.0f, 1));
		engine::setCameraPos(vec4(41.5f, 19.5f, 21.0f, 1));

		disableCamRot = !disableCamRot;

		if (!disableCamRot)
			engine::setTargetPos(CAM_POS_4 + CAM_FORWARD);
	}
	break;
	case 27:
		exit(0);
		break;
	}

	switch (selectedIndex)
	{
	case 1:
		ceilingFanKeyboard(key, mouseX, mouseY);
		break;
	case 2:
		fan1Keyboard(key, mouseX, mouseY);
		break;
	case 3:
		
		break;
	case 4:

		break;
	case 5:
		cabinetKeyboard(key, mouseX, mouseY);
		break;
	case 6:
		break;
	default:
		break;
	}

	glutPostRedisplay();
}


void resharp(int w, int h)
{
	setupCamera(w, h, 0.1f, 1000);
	ui::screenChange(w, h);

	glutReshapeWindow(w, h);
	glViewport(0, 0, w, h);
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	btnAxes.onEvent(button, state, x, y);
	btnDay.onEvent(button, state, x, y);
	btnNight.onEvent(button, state, x, y);
	btnSunset.onEvent(button, state, x, y);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		leftMouseButtonDown = true;
		lastMouseX = x;
		lastMouseY = y;
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		leftMouseButtonDown = false;
	}
}

void motion(int x, int y)
{
	if (leftMouseButtonDown && !disableCamRot)
		cameraMotion(x, y, lastMouseX, lastMouseY);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glEnable(GL_MULTISAMPLE);
	glutInitWindowSize(840, 600);
	glutInitWindowPosition(250, 250);
	glutCreateWindow("Render Engine");

	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cerr << "GLEW Init Error: " << glewGetErrorString(err) << std::endl;
		return -1;
	}

	glutDisplayFunc(display);
	glutReshapeFunc(resharp);
	glutIdleFunc(idle);
	glutTimerFunc(20, timer, 0);
	glutKeyboardFunc(input);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);



	initialize_before_display();


	glutMainLoop();

	engine::disposeLights();

	return 0;
}