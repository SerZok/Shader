#pragma once
#include <string>
#include <iostream>
#include "glew-2.1.0/include/GL/glew.h"
#include "IL/il.h"
#include "IL/ilu.h"
#include "IL/ilut.h"

// ������������ ��� ����������� ������ ����������
enum class TextureFilter {
	POINT, // ��������
	BILINEAR, // ����������
	TRILINEAR, // �����������
	ANISOTROPIC // ������������
};

class Texture
{
public:
	Texture();
	// �������� �������� �� �������� �����
	void load(std::string filename);

	// ���������� �������� (�������� � ����������� ����� � ��������� ����������)
	void bind(GLenum texUnit = GL_TEXTURE0);
	// ���������� ��������������� ��� ���� ���������� ������
	static void disableAll();
private:
	// ������������� (������) ����������� �������
	GLuint texIndex;
};