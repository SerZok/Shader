#include "Simulation.h"


float last_time = 0.0;
float getSimulationTime() {
	clock_t current_time = clock();
	float simulationTime = float(current_time - last_time) / CLOCKS_PER_SEC;
	last_time = current_time;
	return simulationTime;
}

void simulation() {
	float simulationTime = getSimulationTime();
	offset[0] += speed[0] * simulationTime;
	if (offset[0] >= 0.5) {
		offset[0] = 0.5;
		speed[0] *= -1;
	}
	if (offset[0] <= -0.5) {
		offset[0] = -0.5;
		speed[0] *= -1;
	}
	offset[1] += speed[1] * simulationTime;
	if (offset[1] >= 0.5) {
		offset[1] = 0.5;
		speed[1] *= -1;
	}
	if (offset[1] <= -0.5) {
		offset[1] = -0.5;
		speed[1] *= -1;
	}
	glutPostRedisplay();
}