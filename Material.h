#pragma once
#include "glew-2.1.0/include/GL/glew.h"
#include "GL/freeglut.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <iostream>
#include "rapidjson/document.h"

using namespace std;
using namespace glm;
using namespace rapidjson;

class Material
{
public:
	Material();
	bool loadFromJson(std::string filename);
	glm::vec4& getAmbient();
	glm::vec4& getDiffuse();
	glm::vec4& getSpecular();
	float getShininess();
private:
	glm::vec4 ambient;
	glm::vec4 diffuse;
	glm::vec4 specular;
	GLfloat shininess;
};