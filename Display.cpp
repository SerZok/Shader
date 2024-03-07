#include "Display.h"
int final_time, FPS, init_time = time(NULL);
int mCurrentTick;

void getFPS() {
	FPS = mCurrentTick / (final_time - init_time);
	init_time = time(NULL);
	char windowTitle[50];
	sprintf_s(windowTitle, 50, "made by SergeyZ FPS : %i", mCurrentTick);
	glutSetWindowTitle(windowTitle);
	mCurrentTick = 0;
}

void display(void){
	// отчищаем буфер цвета и буфер глубины
	glClearColor(1.00, 1.00, 0100, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// включаем тест глубины
	glEnable(GL_DEPTH_TEST);
	// активируем шейдер
	shader.activate();
	shader.setUniform("offset", offset);
	shader.setUniform("color1", color1);
	shader.setUniform("color2", color2);
	// выводим прямоугольник 
	drawObject();
	// смена переднего и заднего буферов
	glutSwapBuffers();
	
	//FPS
	mCurrentTick++;
	if ((final_time - init_time) >= 1)
		getFPS();
	final_time = time(NULL);
}