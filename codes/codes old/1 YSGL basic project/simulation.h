#ifndef YSGL_sim
#define YSGL_sim
#include <YSGLall.h>

YSCamera myCam;

void YSGL_init()
{
	ysgl_about_mb();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	myCam.Position.z = 2.5;
}

void YSGL_mainGL()
{
	static float theta = 0.0f;
	glPushMatrix();
	{
		glRotatef(theta, 0.0f, 0.0f, 1.0f);
		glBegin(GL_TRIANGLES);
		{
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex2f(0.0f, 1.0f);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex2f(0.87f, -0.5f);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex2f(-0.87f, -0.5f);
		}
		glEnd();
	}
	glPopMatrix();
	theta += 1.0f;
	Sleep(1);
}

#endif