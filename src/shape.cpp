#include "shape.h"

#include <iostream>
using namespace std;
GLuint LoadTexture(const string filename){
	GLuint id;
	FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(filename.c_str(), 0);
	FIBITMAP *dib = FreeImage_Load(fif, filename.c_str());
	BYTE *buf = FreeImage_GetBits(dib);
	unsigned int width = FreeImage_GetWidth(dib);
	unsigned int height = FreeImage_GetHeight(dib);
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	GLenum image_format = GL_RGB;		//format the image is in
	GLint internal_format = GL_BGR_EXT;	//format to store the image in

	int bpp = FreeImage_GetBPP(dib);
	if (bpp == 32){
		image_format = GL_RGBA;
		internal_format = GL_BGRA_EXT;
	}

	cout << width << endl;
	glTexImage2D(GL_TEXTURE_2D, 0, image_format, width, height,0, internal_format, GL_UNSIGNED_BYTE, buf);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);

	return id;
}

void DrawAxis(){

	glLineWidth(4);
	glBegin(GL_LINES);
		glColor3ub(255, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glColor3ub(0, 255, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
		glColor3ub(0, 0, 255);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 1);
	glEnd();
	glLineWidth(1);
	
	double base = 0.05, height = 0.10;
	int slices = 10, stacks = 10;
	glColor3ub(255, 0, 0);
    glPushMatrix();  
    glTranslatef(1.0f,0.0f,0.0f);  
    glRotatef(90.0f,0.0f,1.0f,0.0f);  
    glutWireCone(base,height,slices,stacks);  
    glPopMatrix();  
  
	glColor3ub(0, 255, 0);
    glPushMatrix();  
    glTranslatef(0.0f,1.0f,0.0f);  
    glRotatef(-90.0f,1.0f,0.0f,0.0f);  
    glutWireCone(base,height,slices,stacks);  
    glPopMatrix();  
  
	glColor3ub(0, 0, 255);
    glPushMatrix();  
    glTranslatef(0.0f,0.0f,1.0f);  
    glRotatef(90.0f,0.0f,0.0f,1.0f);  
    glutWireCone(base,height,slices,stacks);  
    glPopMatrix();  
}	

void DrawGround(){
	glLineWidth(2);
	const int K = 5;
	glColor3ub(127,127,127);
	glBegin(GL_LINES);
	for (int x = -K; x <= K;++x){
		glVertex3f(x,-K,0);
		glVertex3f(x,K,0);
	}
	for (int y = -K; y <= K;++y){
		glVertex3f(-K,y,0);
		glVertex3f(K,y,0);
	}
	glEnd();
	glLineWidth(0);
}
