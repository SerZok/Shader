#include "RenderManager.h"

void RenderManager::init() {
	Shader shader;
	shader.load("SHADERS\\Example.vsh", "SHADERS\\Example.fsh");
	shaders.push_back(shader);
}

void RenderManager::start() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);

	shaders[0].activate();
	mat4& projectionMatrix = camera->getProjectionMatrix();
	shaders[0].setUniform("projectionMatrix", projectionMatrix);

	graphicObjects.clear();
}

void RenderManager::setCamera(Camera* camera) {
	this->camera = camera;
}

void RenderManager::addToRenderQueue(GraphicObject& graphicObject) {
	graphicObjects.push_back(graphicObject);
}

void RenderManager::finish() {
	mat4& viewMatrix = camera->getViewMatrix();
	for (auto& graphicObject : graphicObjects) {
		mat4 modelViewMatrix = viewMatrix * graphicObject.getModelMatrix();
		shaders[0].setUniform("modelViewMatrix", modelViewMatrix);

		shaders[0].setUniform("color", graphicObject.getColor());

		int textureId = graphicObject.getTextureId();
		Texture* texture = ResourceManager::instance().getTexture(textureId);
		if (texture != nullptr) {
			texture->bind(GL_TEXTURE0);
		}

		shaders[0].setUniform("texture_0", 0);

		int meshId = graphicObject.getMeshId();
		Mesh* mesh = ResourceManager::instance().getMesh(meshId);
		if (mesh != nullptr) {
			mesh->drawOne();
		}
		Texture::disableAll();
	}
}