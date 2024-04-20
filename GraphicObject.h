#pragma once
#include "glew-2.1.0/include/GL/glew.h"
#include "GL/freeglut.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;
using namespace std;

// КЛАСС ДЛЯ РАБОТЫ С ГРАФИЧЕСКИМ ОБЪЕКТОМ
class GraphicObject
{
public:
	// конструктор по умолчанию
	GraphicObject();
	// установить цвет объекта
	void setColor(vec4& color);
	// установить позицию объекта
	void setPosition(vec3& position);
	// установить угол поворота в градусах относительно оси OY по часовой стрелке
	void setAngleOY(float degree);
	void setTextureId(int Id);
	void setMeshId(int id);
	void setMaterialId(int id);

	vec4& getColor();
	mat4& getModelMatrix();
	int getMeshId();
	int getTextureId();
	int getMaterialId();

private:
	int meshId;
	int textureId;
	int materialId;

	// цвет объекта
	vec4 color;
	// матрица модели (задает позицию и ориентацию)
	mat4 modelMatrix;
	
};
