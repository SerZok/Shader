#include "Data.h"
#include "Display.h"

char window_title[256];

Camera camera;
Shader shader;
Light light;
vector <GraphicObject>graphicObjects;



// функци€ дл€ инициализации всех общих данных (камера, объекты и т.д.)
void initData() {
	RenderManager::instance().init();
	ResourceManager& resourceManger = ResourceManager::instance();

	int meshId = -1;
	int textureId = -1;
	int materialId = -1;
	GraphicObject graphicObject;

	//ƒќћ
	meshId = resourceManger.loadMesh("MESHES\\buildings\\house_2.obj");
	textureId = resourceManger.loadTexture("TEXTURES\\buildings\\house_2_orange.png");
	materialId = resourceManger.loadMaterial("MATERIALS\\dull_material.json");
	vec4 color1 = vec4(0.2, 0.2, 0.2, 1);
	vec3 pos1 = vec3(0, 0, 0);

	graphicObject.setMeshId(meshId);
	graphicObject.setTextureId(textureId);
	graphicObject.setMaterialId(materialId);
	graphicObject.setColor(color1);
	graphicObject.setPosition(pos1);
	graphicObject.setAngleOY(0.0);
	graphicObjects.push_back(graphicObject);


	//ƒерево
	meshId = resourceManger.loadMesh("MESHES\\natures\\big_tree.obj");
	textureId = resourceManger.loadTexture("TEXTURES\\natures\\nature.png");
	materialId = resourceManger.loadMaterial("MATERIALS\\dull_material.json");
	vec4 color2 = vec4(0.2, 0.2, 0.2, 1);
	vec3 pos2 = vec3(7.5, -0.75, 2.5);

	graphicObject.setMeshId(meshId);
	graphicObject.setTextureId(textureId);
	graphicObject.setMaterialId(materialId);
	graphicObject.setColor(color2);
	graphicObject.setPosition(pos2);
	graphicObject.setAngleOY(0.0);
	graphicObjects.push_back(graphicObject);

	//—камейка
	meshId = resourceManger.loadMesh("MESHES\\props\\bench_1.obj");
	textureId = resourceManger.loadTexture("TEXTURES\\props\\props.png");
	materialId = resourceManger.loadMaterial("MATERIALS\\shiny_material.json");
	vec4 color3 = vec4(0.2, 0.2, 0.2, 1);
	vec3 pos3 = vec3(-6.5, -2, 2.5);

	graphicObject.setMeshId(meshId);
	graphicObject.setTextureId(textureId);
	graphicObject.setMaterialId(materialId);
	graphicObject.setColor(color3);
	graphicObject.setTextureId(textureId);
	graphicObject.setPosition(pos3);
	graphicObject.setAngleOY(45.0);
	graphicObjects.push_back(graphicObject);

	//Jeep
	meshId = resourceManger.loadMesh("MESHES\\vehicles\\jeep.obj");
	textureId = resourceManger.loadTexture("TEXTURES\\vehicles\\jeep_green.png");
	materialId = resourceManger.loadMaterial("MATERIALS\\shiny_material.json");
	vec4 color4 = vec4(0.2, 0.2, 0.2, 1);
	vec3 pos4 = vec3(3.5, -1.6, 6.5);

	graphicObject.setMeshId(meshId);
	graphicObject.setTextureId(textureId);
	graphicObject.setMaterialId(materialId);
	graphicObject.setColor(color4);
	graphicObject.setTextureId(textureId);
	graphicObject.setPosition(pos4);
	graphicObject.setAngleOY(90.0);
	graphicObjects.push_back(graphicObject);

}

// функци€ дл€ вывода квадрата с ребрами равными единице (от -0.5 до +0.5)
void drawObject(){
	// переменные дл€ вывода объекта (пр€моугольника из двух треугольников)
	static bool init = true;
	static GLuint VAO_Index = 0;		// индекс VAO-буфера
	static GLuint VBO_Index = 0;		// индекс VBO-буфера
	static int VertexCount = 0;			// количество вершин

	// при первом вызове инициализируем VBO и VAO
	if (init) {
		init = false;
		// создание и заполнение VBO
		glGenBuffers(1, &VBO_Index);
		glBindBuffer(GL_ARRAY_BUFFER, VBO_Index);
		GLfloat Verteces[] = {
			// передн€€ грань (два треугольника)
			-0.5, +0.5, +0.5, -0.5, -0.5, +0.5, +0.5, +0.5, +0.5,
			+0.5, +0.5, +0.5, -0.5, -0.5, +0.5, +0.5, -0.5, +0.5,
			// задн€€ грань (два треугольника)
			+0.5, +0.5,	-0.5, +0.5, -0.5, -0.5, -0.5, +0.5, -0.5,
			-0.5, +0.5,	-0.5, +0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
			// права€ грань (два треугольника) 
			+0.5, -0.5,	+0.5, +0.5, -0.5, -0.5, +0.5, +0.5, +0.5,
			+0.5, +0.5,	+0.5, +0.5, -0.5, -0.5, +0.5, +0.5, -0.5,
			// лева€ грань (два треугольника)
			-0.5, +0.5,	+0.5, -0.5, +0.5, -0.5, -0.5, -0.5, +0.5,
			-0.5, -0.5,	+0.5, -0.5, +0.5, -0.5, -0.5, -0.5, -0.5,
			// верхн€€ грань (два треугольника)
			-0.5, +0.5, -0.5, -0.5, +0.5, +0.5, +0.5, +0.5, -0.5,
			+0.5, +0.5, -0.5, -0.5, +0.5, +0.5, +0.5, +0.5, +0.5,
			// нижн€€ грань (два треугольника)
			-0.5, -0.5, +0.5, -0.5, -0.5, -0.5, +0.5, -0.5, +0.5,
			+0.5, -0.5, +0.5, -0.5, -0.5, -0.5, +0.5, -0.5, -0.5
		};
		glBufferData(GL_ARRAY_BUFFER, sizeof(Verteces), Verteces, GL_STATIC_DRAW);

		// создание VAO
		glGenVertexArrays(1, &VAO_Index);
		glBindVertexArray(VAO_Index);
		// заполнение VAO
		glBindBuffer(GL_ARRAY_BUFFER, VBO_Index);
		int location = 0;
		glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(location);
		// "отв€зка" буфера VAO, чтоб случайно не испортить
		glBindVertexArray(0);

		// указание количество вершин
		VertexCount = 6*6;
		init = false;
	}

	// выводим пр€моугольник
	glBindVertexArray(VAO_Index);
	glDrawArrays(GL_TRIANGLES, 0, VertexCount);
}