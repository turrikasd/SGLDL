// SGLDL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

Game* gamePointer;
int wi, he;

void sgInit(int argc, char* argv[], int width, int height, Game* game)
{
	gamePointer = game;
	wi = width;
	he = height;

	// Init GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);

	// Create Window
	glutCreateWindow("Game1");

	InitRendering(); // function

	// Set handler functions
	glutDisplayFunc(DrawScene);
	glutKeyboardFunc(HandleKeypress);
	glutReshapeFunc(HandleResize);

	glutTimerFunc(17.0f, sgUpdate, 0);
}

void sgStartMainLoop()
{
	glutMainLoop();
}

void InitRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}

void sgUpdate(int value)
{
	gamePointer->Update();
	glutTimerFunc(17.0f, sgUpdate, 0);
}

void HandleResize(int w, int h)
{
	//sgClearToGLProjection();

	gamePointer->SetWindowWidth(w);
	gamePointer->SetWindowHeight(h);

	wi = w;
	he = h;
}

void HandleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case VK_ESCAPE:
		exit(0);
	}
}

void sgClearToGLProjection()
{
	// Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, wi, he);

	glMatrixMode(GL_PROJECTION);

	// Set the camera perspective
	glLoadIdentity(); // Reset the camera

	gluPerspective(45.0, (double)wi / (double)he, 1.0, 200.0f);
}

void DrawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); // Switch to drawing perspective
	glLoadIdentity(); // Reset the drawing perspective

	glTranslatef(0, 0, -5.0f);
	//gluOrtho2D(-1, 1, -1, 1);
	//gamePointer->Draw2D();


	sgClearToGLProjection();
	glMatrixMode(GL_MODELVIEW); // Switch to drawing perspective
	gamePointer->Draw3D();

	glutSwapBuffers(); // Swap front and back buffers
}

GLuint sgLoadTexture(Image* image)
{
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB,
				 image->width, image->height,
				 0,
				 GL_RGB,
				 GL_UNSIGNED_BYTE,
				 image->pixels);

	return textureId;
}

void sgDrawTriangle(Vector3 position)
{
	glBegin(GL_TRIANGLES);

	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);

	glEnd();
}

void sgDrawSquare(Vector3 position, Quaternion rotation, float scale, Color color)
{
	glPushMatrix();

	glTranslatef(position.x, position.y, position.x);
	glRotated(rotation.w, rotation.x, rotation.y, rotation.z);
	glScalef(scale, scale, scale);

	glBegin(GL_QUADS);
	
	glColor4f(color.r, color.g, color.b, color.a);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glEnd();

	glPopMatrix();
}

void sgDrawSquare(Vector3 position, Texture2D texture)
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);

	glEnd();

	glPopMatrix();
}

void sgSetClearColor(Color color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}