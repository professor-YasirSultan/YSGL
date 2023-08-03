#ifndef YSGL_sim
#define YSGL_sim
#include <YSGLall.h>

//YS3dModel_OBJ myHeli, myTree;
YSCamera myCam;
YSTexture texRoad, texMou, texGround, texCoord0;

void YSGL_init()
{
	char SuperFolder[] = "D:\\resources\\";
	ysgl_about_mb();
	ysgl_ver_mb();

	texMou.load("texture\\sky.bmp", SuperFolder);
	texGround.load("texture\\earth.bmp", SuperFolder);
	texRoad.load("texture\\road.bmp", SuperFolder);
	texCoord0.load("texture\\a.bmp", SuperFolder);

	myCam.Position.z = 10;
	myCam.Position.y = 2;
}

void YSGL_mainGL()
{
	static float xxx = 0;

	static float theta = 0;
	theta += 1;

	glPushMatrix();
	{
		glRotatef(90, 1, 0, 0);
		texCoord0.draw();
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(0, ysSinD(theta) + 2, 0);
		//glRotatef(theta , 1,0,0);
		glColor3f(1, 0, 0);
		ysPrintf("YSGL frame %.0f", theta);
	}
	glPopMatrix();


	glPushMatrix();
	{
		glTranslatef(0, 60, -25);
		texMou.draw(60,15,30);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glRotatef(90, 1, 0, 0);
		texGround.draw(40, 30, 30);
	}
	glPopMatrix();


	glPushMatrix();
	{
		float a = 60, b = 15;
		glTranslatef(0, 0.1, -5);
		glRotatef(90, 1, 0, 0);
		glScalef(15, 1, 1);
		texRoad.draw(3.5, 20, 2);
	}
	glPopMatrix();



	if (keys['Z'])
		xxx -= 0.1;
	if (keys['X'])
		xxx += 0.1;

	Sleep(10);
}

#endif