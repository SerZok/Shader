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


	vec4& getColor();
	mat4& getModelMatrix();

	void setMeshId(int id);
	int getMeshId();
	int getTextureId();
private:
	// ������������� ������������� ����
	int meshId;

	int textureId;
	// ���� �������
	vec4 color;
	// ������� ������ (������ ������� � ����������)
	mat4 modelMatrix;

};
