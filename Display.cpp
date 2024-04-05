#include "Display.h"
int final_time, FPS, init_time = time(NULL);
int mCurrentTick;
int tick;

void printFPS() {
	FPS = mCurrentTick / (final_time - init_time);
	init_time = time(NULL);
	char windowTitle[50];
	sprintf_s(windowTitle, 50, "LAB_3 | FPS : %i |", mCurrentTick);
	glutSetWindowTitle(windowTitle);
	mCurrentTick = 0;
}

void display(void){
	// ������� ������ �����
	glClearColor(0.9, 0.9, 0.9, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// ��������� ����� ������� (�� ������ ������)
	glEnable(GL_DEPTH_TEST);
	// ����� ��������� � ���� ����� � ���������� ��������� ������
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// ��������� �������
	shader.activate();

	// ������������� ������� ��������
	mat4& projectionMatrix = camera.getProjectionMatrix();
	shader.setUniform("projectionMatrix", projectionMatrix);

	// ������������� ������� ������
	mat4& viewMatrix = camera.getViewMatrix();

	//������� ��� �������
	for (auto& grObj : graphicObjects) {
		// ������������� ������� ���������� ������
		mat4 modelViewMatrix = viewMatrix * grObj.getModelMatrix();
		shader.setUniform("modelViewMatrix", modelViewMatrix);

		// ������������� ����
		shader.setUniform("color", grObj.getColor());
		
		//������� ������ ������
		drawObject();
	}

	// ����� ��������� � ������� �������
	glutSwapBuffers();
	
	//FPS
	mCurrentTick++;
	if ((final_time - init_time) >= 1)
		printFPS();
	final_time = time(NULL);

	tick++;
	if (tick > 360)
		tick = 0;
}