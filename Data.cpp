#include "Data.h"
#include "Display.h"

char window_title[256];

Camera camera;
Shader shader;
vector <GraphicObject>graphicObjects;


// функци€ дл€ инициализации всех общих данных (камера, объекты и т.д.)
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