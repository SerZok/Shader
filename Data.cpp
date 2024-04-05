#include "Data.h"
#include "Display.h"

char window_title[256];

Camera camera;
Shader shader;
vector <GraphicObject>graphicObjects;


// ������� ��� ������������� ���� ����� ������ (������, ������� � �.�.)
void initData() {
	GraphicObject obj;
	float ang = 0;
	vec4 col0 = vec4(0, 0, 0, 1);
	vec3 pos0 = vec3(0, 0, 0);
	obj.setColor(col0);
	obj.setPosition(pos0);
	graphicObjects.push_back(obj);
	for (int i = 0; i < 1000; i++) {
		vec4 color = vec4(sin(i/3), sin(i/4), sin(i/5), 1);
		vec4 color2 = vec4(cos(i/3), cos(i/4), cos(i/5), 1);
		
		if (i %2 == 0) {
			obj.setColor(color2);
		}
		else {
			obj.setColor(color);
		}
		vec3 pos = vec3(i*sin(i), 0, i*cos(-i));
		obj.setPosition(pos);
		obj.setAngle(ang);
		ang += 15;
		graphicObjects.push_back(obj);
	}
}
// ������� ��� ������ �������� � ������� ������� ������� (�� -0.5 �� +0.5)
void drawObject(){
	


	// ���������� ��� ������ ������� (�������������� �� ���� �������������)
	static bool init = true;
	static GLuint VAO_Index = 0;		// ������ VAO-������
	static GLuint VBO_Index = 0;		// ������ VBO-������
	static int VertexCount = 0;			// ���������� ������

	// ��� ������ ������ �������������� VBO � VAO
	if (init) {
		init = false;
		// �������� � ���������� VBO
		glGenBuffers(1, &VBO_Index);
		glBindBuffer(GL_ARRAY_BUFFER, VBO_Index);
		GLfloat Verteces[] = {
			// �������� ����� (��� ������������)
			-0.5, +0.5, +0.5, -0.5, -0.5, +0.5, +0.5, +0.5, +0.5,
			+0.5, +0.5, +0.5, -0.5, -0.5, +0.5, +0.5, -0.5, +0.5,
			// ������ ����� (��� ������������)
			+0.5, +0.5,	-0.5, +0.5, -0.5, -0.5, -0.5, +0.5, -0.5,
			-0.5, +0.5,	-0.5, +0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
			// ������ ����� (��� ������������) 
			+0.5, -0.5,	+0.5, +0.5, -0.5, -0.5, +0.5, +0.5, +0.5,
			+0.5, +0.5,	+0.5, +0.5, -0.5, -0.5, +0.5, +0.5, -0.5,
			// ����� ����� (��� ������������)
			-0.5, +0.5,	+0.5, -0.5, +0.5, -0.5, -0.5, -0.5, +0.5,
			-0.5, -0.5,	+0.5, -0.5, +0.5, -0.5, -0.5, -0.5, -0.5,
			// ������� ����� (��� ������������)
			-0.5, +0.5, -0.5, -0.5, +0.5, +0.5, +0.5, +0.5, -0.5,
			+0.5, +0.5, -0.5, -0.5, +0.5, +0.5, +0.5, +0.5, +0.5,
			// ������ ����� (��� ������������)
			-0.5, -0.5, +0.5, -0.5, -0.5, -0.5, +0.5, -0.5, +0.5,
			+0.5, -0.5, +0.5, -0.5, -0.5, -0.5, +0.5, -0.5, -0.5
		};
		glBufferData(GL_ARRAY_BUFFER, sizeof(Verteces), Verteces, GL_STATIC_DRAW);

		// �������� VAO
		glGenVertexArrays(1, &VAO_Index);
		glBindVertexArray(VAO_Index);
		// ���������� VAO
		glBindBuffer(GL_ARRAY_BUFFER, VBO_Index);
		int location = 0;
		glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(location);
		// "�������" ������ VAO, ���� �������� �� ���������
		glBindVertexArray(0);

		// �������� ���������� ������
		VertexCount = 6*6;
		init = false;
	}

	// ������� �������������
	glBindVertexArray(VAO_Index);
	glDrawArrays(GL_TRIANGLES, 0, VertexCount);
}