#include "GraphicObject.h"
// ����������� �� ���������
GraphicObject::GraphicObject() {
	modelMatrix = mat4(
		vec4(1, 0, 0, 0), // 1-�� �������: ����������� ��� X
		vec4(0, 1, 0, 0), // 2-�� �������: ����������� ��� Y
		vec4(0, 0, 1, 0), // 3-�� �������: ����������� ��� Z
		vec4(0, 0, 0, 1)); // 4-�� �������: ������� ������� (������ ���������)
	color = vec4(1, 0, 0, 1);
}
// ���������� ���� �������
void GraphicObject::setColor(vec4& color) {
	this->color = color;
}
// ���������� ������� �������
void GraphicObject::setPosition(vec3& position) {
	modelMatrix[3][0] = position.x;
	modelMatrix[3][1] = position.y;
	modelMatrix[3][2] = position.z;
}
// ���������� ���� �������� � �������� ������������ ��� OY �� ������� �������
void GraphicObject::setAngleOY(float degree) {
	float rad = radians(degree);
	modelMatrix[0][0] = cos(rad);
	modelMatrix[0][2] = sin(rad);
	modelMatrix[2][0] = -sin(rad);
	modelMatrix[2][2] = cos(rad);
}



// �������� ��������� ���������
vec4& GraphicObject::getColor() {
	return color;
}
mat4& GraphicObject::getModelMatrix() {
	return modelMatrix;
}

void GraphicObject::setMeshId(int id) {
	meshId = id;
}

int GraphicObject::getMeshId() {
	return meshId;
}

//
//vec3 GraphicObject::getPosition() {
//	return vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);
//}