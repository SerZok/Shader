﻿#include <Windows.h>
#include "stdio.h"

#include "glew-2.1.0/include/GL/glew.h"
#include "GL/freeglut.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Display.h"
#include "Simulation.h"
#include "Shader.h"


// используемые пространства имен (для удобства)
using namespace glm;
using namespace std;

// функция, вызываемая при изменении размеров окна
void reshape(int w, int h){
	// установить новую область просмотра, равную всей области окна
	glViewport(0, 0, w, h);
	camera.setProjectionMatrix(50.0f, (float)w / h, 1.0f, 500.0f);
}

// основная функция
void main(int argc, char** argv){
	// инициализация библиотеки GLUT
	glutInit(&argc, argv);
	// инициализация дисплея (формат вывода)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL | GLUT_MULTISAMPLE);
	// требования к версии OpenGL (версия 3.3 без поддержки обратной совместимости)
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// устанавливаем верхний левый угол окна
	glutInitWindowPosition(10, 50);
	// устанавливаем размер окна
	glutInitWindowSize(1280, 720);
	// создание окна
	glutCreateWindow("laba_02");

	// инициализация GLEW 
	GLenum err = glewInit();
	if (GLEW_OK != err){
		fprintf(stderr, "Glew error: %s\n", glewGetErrorString(err));
		return;
	}

	initData();

	// определение текущей версии OpenGL
	printf("OpenGL Version = %s\n\n", glGetString(GL_VERSION));

	// загрузка шейдера
	shader.load("SHADER\\Example.vsh", "SHADER\\Example.fsh");

	// устанавливаем функцию, которая будет вызываться для перерисовки окна
	glutDisplayFunc(display);
	// устанавливаем функцию, которая будет вызываться при изменении размеров окна
	glutReshapeFunc(reshape);
	// устанавливаем функцию которая вызывается всякий раз, когда процессор простаивает
	glutIdleFunc(simulation);
	// основной цикл обработки сообщений ОС
	glutMainLoop();
	return;
}