#include "Camera.h"
Camera::Camera() {
	cameraPosition = vec3(10, 10, 1);
	observationPoint = vec3(0, 0, 0);
	dMove = vec3(0, 0, 0);
	radius = length(cameraPosition - observationPoint);
	vec3 v1 = cameraPosition;
	vec3 v2 = vec3(v1.x, 0, v1.z);
	float cos_y = dot(normalize(v1), normalize(v2));
	float cos_x = dot(normalize(v2), vec3(1, 0, 0));
	vertAng = 90 - degrees(acos(cos_y));
	horizAng = degrees(acos(cos_x));

	viewMatrix = lookAt(cameraPosition, observationPoint, vec3(0, 1, 0));
}
// ���������� ������� ��������
void Camera::setProjectionMatrix(float fovy, float aspect, float zNear, float zFar) {
	projectionMatrix = perspective(radians(fovy), aspect, zNear, zFar);
}
// �������� ������� ��������
mat4& Camera::getProjectionMatrix() {
	return projectionMatrix;
}

// �������� ������� ����
mat4& Camera::getViewMatrix() {
	return viewMatrix;
}
// ����������� ������ � ����� ���������� � �������������� ��������� (OXZ)
void Camera::moveOXZ(float dx, float dz) {
	float angle = radians(horizAng);
	float angle2 = radians(90 + horizAng);
	dMove += vec3(dx * cos(angle), 0, dx * sin(angle));
	dMove += vec3(dz * cos(angle2), 0, dz * sin(angle2));
	recalculateViewMatrix();
}
// ��������� � �������������� � ������������ ��������� (���� �������� � ��������)
void Camera::rotate(float horizAngle, float vertAngle) {
	horizAng += horizAngle;
	vertAng += vertAngle;

	if (vertAng > 89)
		vertAng = 89;

	if (vertAng < 0) 
		vertAng = 0;

	recalculateViewMatrix();
}

void Camera::zoom(float dR) {
	radius += dR;
	if (radius > 50)
		radius = 50;

	if (radius < 1)
		radius = 1;
	recalculateViewMatrix();
}

void Camera::recalculateViewMatrix() {
	float rad_v = radians(vertAng);
	float rad_h = radians(horizAng);
	cameraPosition.x = radius * sin(rad_v) * cos(rad_h);
	cameraPosition.y = radius * cos(rad_v);
	cameraPosition.z = radius * sin(rad_v) * sin(rad_h);
	cameraPosition += dMove;
	observationPoint = dMove;
	viewMatrix = lookAt(cameraPosition, observationPoint, vec3(0, 1, 0));
}