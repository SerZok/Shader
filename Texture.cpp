#include "Texture.h"


using namespace std;
Texture::Texture() {

}

void Texture::load(std::string filename) {

	ILuint imageID = ilGenImage();
	ilBindImage(imageID);
	
	std::wstring filename_w(filename.begin(), filename.end());
	if (ilLoadImage(filename_w.c_str())) {
		cout << "Texture: " << filename << " open success\n";
	}
	else {
		cout << "ERROR: " << filename << " !\n";
		return;
	}
	int width = ilGetInteger(IL_IMAGE_WIDTH);
	int	height = ilGetInteger(IL_IMAGE_HEIGHT);
	int	format = ilGetInteger(IL_IMAGE_FORMAT);
	int type = ilGetInteger(IL_IMAGE_TYPE);
	cout <<"Width: " << width << "\nHeight: " << height << "\nFormat: " << format << "\nType: " << type << endl<<endl;
	char* pixels = new char[width * height * 4];
	ilCopyPixels(0, 0, 0, width, height, 1, IL_RGBA, IL_UNSIGNED_BYTE, pixels);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &texIndex);
	glBindTexture(GL_TEXTURE_2D, texIndex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	delete[] pixels;
	glGenerateMipmap(GL_TEXTURE_2D);

	//glTexParameteri
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::bind(GLenum texUnit) {
	glActiveTexture(texUnit);
	glBindTexture(GL_TEXTURE_2D, texIndex);
}


void Texture::disableAll() {
	glBindTexture(GL_TEXTURE_2D, 0);
}