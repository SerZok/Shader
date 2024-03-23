#pragma once
#include <windows.h>
#include <memory>
#include <vector>
#include "glew-2.1.0/include/GL/glew.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "GL/freeglut.h"

#include "Shader.h"
#include "Camera.h"
#include "GraphicObject.h"

// используемые пространства имен
using namespace glm;
using namespace std;

extern Camera camera;
extern Shader shader;

// СПИСОК ГРАФИЧЕСКИХ ОБЪЕКТОВ ДЛЯ ВЫВОДА НА ЭКРАН
extern vector <GraphicObject>graphicObjects;

void initData();
void drawObject();