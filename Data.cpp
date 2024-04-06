#include "Data.h"
#include "Display.h"

char window_title[256];

Camera camera;
Shader shader;
vector <GraphicObject>graphicObjects;


// ������� ��� ������������� ���� ����� ������ (������, ������� � �.�.)
void initData() {
	vec4 color1 = vec4(0.1, 0.1, 0.1, 1);
	vec4 color2 = vec4(0.0, 0.5, 0.1, 1);
	vec4 color3 = vec4(0.0, 0.5, 0.2, 1);
	vec4 color4 = vec4(0.2, 0.2, 0.7, 1);
	vec4 color5 = vec4(0.2, 0.2, 0.7, 1);
	vec4 color6 = vec4(0.9, 0.4, 0.2, 1);
	vec4 color7 = vec4(0.8, 0.8, 0.2, 1);

	vec3 pos1 = vec3(0, 0, 0);
	vec3 pos2 = vec3(7.5, -0.75, 2.5);
	vec3 pos3 = vec3(-7.5, -0.75, 2.5);
	vec3 pos4 = vec3(+5, -2.15, +6.5);
	vec3 pos5 = vec3(-5, -2.15, +10.5);
	vec3 pos6 = vec3(0, 2.9, 0);
	vec3 pos7 = vec3(-5, -2.15, 5);
	


	// ������ �� �������� �������� (��� ��������)
	ResourceManager& rm = ResourceManager::instance();
	// ��������� ���������� ��� �������� ��������������� ����
	int meshId = -1;
	// ��������� ���������� ��� ������������� ������������ �������
	GraphicObject graphicObject;

	//���
	meshId = rm.loadMesh("MESHES\\buildings\\house_2.obj");
	graphicObject.setMeshId(meshId);
	graphicObject.setColor(color1);
	graphicObject.setPosition(pos1);
	graphicObject.setAngleOY(0.0);
	graphicObjects.push_back(graphicObject);

	//������
	meshId = rm.loadMesh("MESHES\\natures\\big_tree.obj");
	graphicObject.setMeshId(meshId);
	graphicObject.setColor(color2);
	graphicObject.setPosition(pos2);
	graphicObject.setAngleOY(0.0);
	graphicObjects.push_back(graphicObject);

	//������
	meshId = rm.loadMesh("MESHES\\natures\\big_tree.obj");
	graphicObject.setMeshId(meshId);
	graphicObject.setColor(color3);
	graphicObject.setPosition(pos3);
	graphicObject.setAngleOY(0.0);
	graphicObjects.push_back(graphicObject);

	//������
	meshId = rm.loadMesh("MESHES\\vehicles\\police_car.obj");
	graphicObject.setMeshId(meshId);
	graphicObject.setColor(color4);
	graphicObject.setPosition(pos4);
	graphicObject.setAngleOY(-115.0);
	graphicObjects.push_back(graphicObject);

	//����
	meshId = rm.loadMesh("MESHES\\vehicles\\jeep.obj");
	graphicObject.setMeshId(meshId);
	graphicObject.setColor(color6);
	graphicObject.setPosition(pos6);
	graphicObject.setAngleOY(-90.0);
	graphicObjects.push_back(graphicObject);

	
	meshId = rm.loadMesh("MESHES\\props\\bench_1.obj");
	graphicObject.setMeshId(meshId);
	graphicObject.setColor(color7);
	graphicObject.setPosition(pos7);
	graphicObjects.push_back(graphicObject);
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