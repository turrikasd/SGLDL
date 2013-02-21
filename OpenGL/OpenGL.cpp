// OpenGL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


float angle = 0.0f;

/*void HandleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
		case VK_ESCAPE:
			exit(0);
	}
}

void HandleResize(int w, int h)
{
	// Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);

	// Set the camera perspective
	glLoadIdentity(); // Reset the camera
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0f);
}*/

/*
void DrawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); // Switch to the drawing perspective
	glLoadIdentity(); // Reset the drawing perspective

	glTranslatef(0, 0, -5.0f); // Translate everything 5 back

	// Add ambient light
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	// Positioned light
	GLfloat LightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};
	GLfloat LightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPos0);

	// Directional Light
	GLfloat LightColor1[] = {0.5f, 0.4f, 0.4f, 1.0f};
	GLfloat LightPos1[] = {0.5f, 1.0f, 1.0f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPos1);

	glPushMatrix();
	glRotatef(angle, 0, 1, 0);

	glBegin(GL_QUADS);
		// Front
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		// Right
		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		// Back
		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		// Left
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
	glEnd();

	glPopMatrix();

	glutSwapBuffers(); // Swap the back and front buffer
}*/

/*void Update(int value)
{
	angle += 1.0f;

	glutPostRedisplay(); // Tell GLUT the scene has changed
	glutTimerFunc(17.0f, Update, 0);
}*/

int _tmain(int argc, char* argv[])
{
	Game1* game = new Game1();
	game->Initialize(argc, argv);

	//glutTimerFunc(17.0f, Update, 0);

	return 0;
}