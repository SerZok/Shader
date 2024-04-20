#include "ResourceManager.h"

int ResourceManager::loadMesh(string filename) {
	if (meshes_id.count(filename))
		return meshes_id[filename];
	else {
		Mesh mesh;
		mesh.load(filename);
		meshes.push_back(mesh);
		meshes_id.insert(pair<string, int>(filename, meshes.size() - 1));
		return meshes_id[filename];
	}
}

int ResourceManager::loadTexture(string filename) {
	if (textures_id.count(filename))
		return textures_id[filename];
	else {
		Texture texture;
		texture.load(filename);
		textures.push_back(texture);
		textures_id.insert(pair<string, int>(filename, textures.size() - 1));
		return textures_id[filename];
	}
}

int ResourceManager::loadMaterial(string filename) {
	if (materials_id.count(filename)) {
		return materials_id[filename];
	}
	else {
		Material mater;
		mater.loadFromJson(filename);
		materials.push_back(mater);
		materials_id.insert(pair<string, int>(filename, materials.size() - 1));
		return materials_id[filename];
	}
}


Mesh* ResourceManager::getMesh(int index) {
	if (index >= meshes.size())
		return nullptr;
	else
		return &(meshes[index]);
}

Texture* ResourceManager::getTexture(int index) {
	if (index >= textures.size())
		return nullptr;
	else
		return &(textures[index]);
}

Material* ResourceManager::getMaterial(int index) {
	if (index >= materials.size()) {
		return nullptr;
	}
	else {
		return &(materials[index]);
	}
}