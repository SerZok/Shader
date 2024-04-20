#pragma once
#include "glew-2.1.0/include/GL/glew.h"
#include "GL/freeglut.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;
using namespace std;

// ����� ��� ������ � ����������� ��������
class GraphicObject
{
public:
	// ����������� �� ���������
	GraphicObject();
	// ���������� ���� �������
	void setColor(vec4& color);
	// ���������� ������� �������
	void setPosition(vec3& position);
	// ���������� ���� �������� � �������� ������������ ��� OY �� ������� �������
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

	// ���� �������
	vec4 color;
	// ������� ������ (������ ������� � ����������)
	mat4 modelMatrix;
	
};
