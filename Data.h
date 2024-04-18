#pragma once
#include <windows.h>
#include <memory>
#include <vector>
#include "glew-2.1.0/include/GL/glew.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "GL/freeglut.h"

#include "Camera.h"
#include "Shader.h"
#include "GraphicObject.h"
#include "ResourceManager.h"
#include "RenderManager.h"

// ������������ ������������ ����
using namespace glm;
using namespace std;

extern Camera camera;
extern Shader shader;

// ������ ����������� �������� ��� ������ �� �����
extern vector <GraphicObject>graphicObjects;

void initData();
void drawObject();