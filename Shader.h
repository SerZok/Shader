#pragma once
// КЛАСС ДЛЯ РАБОТЫ С ШЕЙДЕРОМ
#include <string>
#include <windows.h>
#include "stdio.h"
#include <iostream>
#include <fstream>

#include "glew-2.1.0/include/GL/glew.h"
#include "GL/freeglut.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <map>

using namespace std;


class Shader{
public:
	// загрузка шейдера из внешних файлов
	bool load(std::string veftexShaderFilename, std::string fragmentShaderFilename);
	// выбор шейдера в качестве текущего
	void activate();
	// отключение шейдера
	static void deactivate();

	void setUniform(std::string name, int value);
	void setUniform(std::string name, float value);
	void setUniform(std::string name, glm::vec2& value);
	void setUniform(std::string name, glm::vec4& value);
	void setUniform(std::string name, glm::mat4& value);
private:
	// создание шейдерного объекта указанного типа
	// и загрузка исходного текста шейдера из указанного файла
	GLuint createShaderObject(GLenum shaderType, std::string filename);

	GLuint getUniformLocation(std::string name);
private:
	static GLuint currentProgram;
	// шейдерная программа (шейдер)
	GLuint program;
	std::map <std::string, GLuint> uniforms;
};