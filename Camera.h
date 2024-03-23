#pragma once
#include <iostream>
#include "glew-2.1.0/include/GL/glew.h"
#include "GL/freeglut.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;
using namespace std;

class Camera
{
public:
	// ����������� �� ���������
	Camera();
	// ���������� ������� ��������
	void setProjectionMatrix(float fovy, float aspect, float zNear, float zFar);
	// �������� ������� ��������
	mat4& getProjectionMatrix();
	// �������� ������� ����
	mat4& getViewMatrix();
	// ����������� ������ � ����� ���������� � �������������� ��������� (OXZ)
	void moveOXZ(float dx, float dz);
	// ��������� � �������������� � ������������ ��������� (���� �������� � ��������)
	void rotate(float horizAngle, float vertAngle);
	// ����������/������� ������ �/�� ����� ����������
	void zoom(float dR);
private:
	// ����������� ������� ����
	void recalculateViewMatrix();
private:
	mat4 projectionMatrix;
	mat4 viewMatrix;
	vec3 cameraPosition;
	vec3 observationPoint;
	vec3 dMove;

	float horizAng;
	float vertAng;
	float radius;
};
