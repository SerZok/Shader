#include "Simulation.h"

#define CAMERA_MOVE_SPEED 10
#define CAMERA_ROTATE_SPEED 0.3
#define CAMERA_ZOOM_SPEED 0.2

POINT previousMouseXY;
POINT currentMouseXY;
float dx = 0;
float dz = 0;
float simulationTime= 0.0;

float last_time = 0.0;
float getSimulationTime() {
	clock_t current_time = clock();
	simulationTime = float(current_time - last_time) / CLOCKS_PER_SEC;
	last_time = current_time;
	return simulationTime;
}

void simulation() {
	// получениче времени симуляции
	simulationTime = getSimulationTime();
	// работа камеры
	cameraSimulation();
	// перерисовать окно
	glutPostRedisplay();
}
void cameraSimulation() {
	float dx = 0;
	float dz = 0;
	float rx = 0;
	float ry = 0;
	
	keyboard(dx, dz ,rx);
	camera.moveOXZ(dx * simulationTime, dz * simulationTime);
	mouse(rx, ry);
	camera.rotate(rx * CAMERA_ROTATE_SPEED, -ry * CAMERA_ROTATE_SPEED);
	glutMouseFunc(mouseWheel);
}

void keyboard(float& dx, float& dz, float& rx) {
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(87))
		dx -= CAMERA_MOVE_SPEED;

	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(83))
		dx += CAMERA_MOVE_SPEED;

	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(65))
		dz += CAMERA_MOVE_SPEED;

	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(68))
		dz -= CAMERA_MOVE_SPEED;

	if (GetAsyncKeyState(81))
		rx += CAMERA_MOVE_SPEED;

	if (GetAsyncKeyState(69))
		rx -= CAMERA_MOVE_SPEED;
}

void mouse(float& rx, float& ry) {
	if (!GetAsyncKeyState(VK_RBUTTON))
		if (GetCursorPos(&currentMouseXY))
			previousMouseXY = currentMouseXY;

	if (GetAsyncKeyState(VK_RBUTTON)) {
		if (GetCursorPos(&currentMouseXY)) {
			if ((currentMouseXY.x != previousMouseXY.x)
				|| (currentMouseXY.y != previousMouseXY.y)) {
				rx = currentMouseXY.x - previousMouseXY.x;
				ry = currentMouseXY.y - previousMouseXY.y;
				previousMouseXY = currentMouseXY;
			}
		}
	}
}

void mouseWheel(int button, int dir, int x, int y) {
	float delta = 0;
	if (button == 4)
		delta += CAMERA_ZOOM_SPEED;

	else if (button == 3)
		delta -= CAMERA_ZOOM_SPEED;
	camera.zoom(delta);
}