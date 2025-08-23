#include "core/camera.h"

using namespace engine;

camera engine::mainCamera;

#pragma region CAMERA LOCAL TRANSFORM

vec3 camera::forward()
{
	vec4 forward4 = (mainCamera.target_position - mainCamera.eye_position);
	return vec3(forward4.x, forward4.y, forward4.z);
}

vec3 camera::up()
{
	vec3 globalCamRight = normalize(cross(mainCamera.up_direction, normalize(CAM_FORWARD)));

	vec3 camUp = normalize(cross(normalize(CAM_FORWARD), globalCamRight));

	return camUp;
}

vec3 camera::right()
{
	vec3 camRight = normalize(cross(CAM_UP, normalize(CAM_FORWARD)));

	return camRight;
}

#pragma endregion


void engine::setupCamera(int window_width, int window_height, float zNear, float zFar)
{
	mainCamera.window_width = window_width;
	mainCamera.window_height = window_height;
	mainCamera.zNear = zNear;
	mainCamera.zFar = zFar;
}

void engine::setCameraPos(const vec4& position)
{
	mainCamera.eye_position = position;
	
	mainCamera.target_position = mainCamera.eye_position + vec3(0, 0, 1);
}

void engine::setTargetPos(const vec4& position)
{
	mainCamera.target_position = position;
}

void engine::moveCam(const vec4& delta)
{
	mainCamera.eye_position += delta;
	mainCamera.target_position += delta;
}

float yaw = 0;

void engine::rotateCam(float deltaX)
{
	yaw += deltaX / 30;
	mainCamera.target_position = vec4(
		mainCamera.eye_position.x +  sin(yaw),
		mainCamera.eye_position.y,
		mainCamera.eye_position.z+  cos(yaw), 1);
}


void engine::setCameraSpeed(float speed)
{
	mainCamera.motionSpeed = speed;
}

float yawAngle = 0;
float pitchAngle = 0;

/// <summary>
/// Rodrigues
/// </summary>
vec3 rotateAxis(const vec3& position, float angle, const vec3& axis)
{
	vec3 a = normalize(axis);
	float cosTheta = std::cos(angle);
	float sinTheta = std::sin(angle);
	return position * cosTheta + cross(a, position) * sinTheta + a * (dot(a, position) * (1 - cosTheta));
}

void engine::cameraMotion(int mouseX, int mouseY, int& lastMouseX, int& lastMouseY)
{
	return;
	int deltaX = mouseX - lastMouseX;
	int deltaY = mouseY - lastMouseY;

	float rotationSpeed = mainCamera.motionSpeed;

	float yaw = deltaX * rotationSpeed;
	float pitch = deltaY * rotationSpeed;
	//float rool = ;

	// HORIZONTAL ROTATION
	if (pitchAngle >= 80 || pitchAngle <= -80)
		yaw *= 0.05f;
	yawAngle += yaw;
	mat4 yawRot = Angel::RotateY(-yaw);
	setCameraPos(yawRot * vec4(CAM_POS_4));

	//VERTICAL ROTATION
	//std::cout << pitch * Deg2Rad << std::endl;
	pitchAngle += pitch;
	if (pitchAngle > 85)
	{
		pitchAngle = 85;
		return;
	}

	if (pitchAngle < -85)
	{
		pitchAngle = -85;
		return;
	}

	vec3 vertical = rotateAxis(CAM_POS_3, pitch * Deg2Rad, CAM_RIGHT);

	//std::cout << pitchAngle << std::endl;
	setCameraPos(vertical);

	//std::cout << CAM_POS_4 << std::endl;
	
	lastMouseX = mouseX;
	lastMouseY = mouseY;
}

void engine::cameraMove(unsigned char key, int mouseX, int mouseY)
{
	switch (key)
	{
	case 'a':
		moveCam(CAM_RIGHT * CAM_MOVE_SPEED);
		break;

	case 'd':
		moveCam( -CAM_RIGHT * CAM_MOVE_SPEED);
		break;
		
	case 's':
		moveCam( -CAM_FORWARD * CAM_MOVE_SPEED);
		break;

	case 'w':
		moveCam( CAM_FORWARD * CAM_MOVE_SPEED);
		break;

	case 'q':
		moveCam(- CAM_UP * CAM_MOVE_SPEED);
		break;

	case 'e':
		moveCam( CAM_UP * CAM_MOVE_SPEED);
		break;
	case 'r':
		rotateCam(1);
		break;

	case 't':
		rotateCam(-1);
		break;
	}
}

void engine::useCameraMatrix(GLuint view_location, GLuint projection_location)
{
	auto camView = LookAt(mainCamera.eye_position, mainCamera.target_position, mainCamera.up_direction);
	glUniformMatrix4fv(view_location, 1, GL_TRUE, camView);

	auto projection = Perspective(60, (float)mainCamera.window_width / mainCamera.window_height, mainCamera.zNear, mainCamera.zFar);
	glUniformMatrix4fv(projection_location, 1, GL_TRUE, projection);
}
