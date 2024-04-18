#pragma once
#include "glew-2.1.0/include/GL/glew.h"
#include "GL/freeglut.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "Data.h"
#include "Shader.h"
#include "Camera.h"
#include "GraphicObject.h"

using namespace glm;
using namespace std;

// ����� ��� �������������� � OPENGL
// ���� ����� �������������� ����� ������������ ��������� ������� ������
class RenderManager
{
public:
	// ������-����� ��� ��������� ���������� ��������� �������.
	static RenderManager& instance()
	{
		static RenderManager renderManager;
		return renderManager;
	}
	// ������������� ������� RenderManager, ����������� ����� ������������� OpenGL:
	// �������� ��������, ��������� ���������� ���������� � ������ �������������
	void init();
	// ������ ������ ���������� ����� (����������, ������� ������� ����������� ��������)
	void start();
	// ��������� ������������ ������
	void setCamera(Camera* camera);
	// ���������� � ������� ���������� ���������� ������� ��� ������
	void addToRenderQueue(GraphicObject& graphicObject);
	// ���������� ������ ����� (�������� ������)
	void finish();
private:
	// ����������� �� ��������� (���������)
	RenderManager() {};
	// ������������ ����������� ���
	RenderManager(const RenderManager& root) = delete;
	// ��������� ������������ ���
	RenderManager& operator=(const RenderManager&) = delete;
private:
	// ������������ �������
	std::vector<Shader> shaders;
	// ��������� �� ������
	Camera* camera;
	// ������ ����������� ��������, ������� ���������� ������� � ������ �����
	std::vector<GraphicObject> graphicObjects;
};