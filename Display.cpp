#include "Display.h"
int final_time, FPS, init_time = time(NULL);
int mCurrentTick;

void printFPS() {
	mCurrentTick++;
	if ((final_time - init_time) >= 1) {
		FPS = mCurrentTick / (final_time - init_time);
		init_time = time(NULL);
		char windowTitle[50];
		sprintf_s(windowTitle, 50, "LAB_6 | FPS : %i |", mCurrentTick);
		glutSetWindowTitle(windowTitle);
		mCurrentTick = 0;
	}
	final_time = time(NULL);
}

void display(void){
	RenderManager& renderManager = RenderManager::instance();
	renderManager.setCamera(&camera);
	// �������� ����� ������ �����
	renderManager.start();

	//����� ������� ���� �������
	for (auto& graphicObject : graphicObjects) {
		renderManager.addToRenderQueue(graphicObject);
	}

	// ��������� ���������� �����
	renderManager.finish();

	// ����� ��������� � ������� �������
	glutSwapBuffers();
	
	printFPS();
}