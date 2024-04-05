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
	// очистка буфера кадра
	glClearColor(0.9, 0.9, 0.9, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// включение теста глубины (на всякий случай)
	glEnable(GL_DEPTH_TEST);
	// вывод полигонов в виде линий с отсечением нелицевых граней
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// активация шейдера
	shader.activate();

	// устанавливаем матрицу проекции
	mat4& projectionMatrix = camera.getProjectionMatrix();
	shader.setUniform("projectionMatrix", projectionMatrix);

	// устанавливаем матрицу камеры
	mat4& viewMatrix = camera.getViewMatrix();

	//выводим все объекты
	for (auto& grObj : graphicObjects) {
		// устанавливаем матрицу наблюдения модели
		mat4 modelViewMatrix = viewMatrix * grObj.getModelMatrix();
		shader.setUniform("modelViewMatrix", modelViewMatrix);

		// устанавливаем цвет
		shader.setUniform("color", grObj.getColor());
		
		//выводим модель кубика
		drawObject();
	}

	// смена переднего и заднего буферов
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