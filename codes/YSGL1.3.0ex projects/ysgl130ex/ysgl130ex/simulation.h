#ifndef YSGL_sim
#define YSGL_sim
#include <YSGLall.h>
#include "YSGL_settings.h"

YS3dModel_OBJ myHeli, myTree;
YSCamera myCam;
YSTexture texRoad, texMou, texGround, texCoord0;
YSTime ysTime;

void YSGL_init()
{
	char SuperFolder[] = "D:\\resources\\";
	YSGLaboutFormShow();

	texMou.load("texture\\sky.bmp", SuperFolder);
	texGround.load("texture\\earth.bmp", SuperFolder);
	texRoad.load("texture\\road.bmp", SuperFolder);
	texCoord0.load("texture\\a.bmp", SuperFolder);


	myCam.Position.z = 10;
	myCam.Position.y = 2;

	myHeli.load("heli\\Heli.obj", "heli\\leviathnbody8bit256.bmp", SuperFolder);
	myHeli.sc = 0.02;
	myTree.load("tree\\tree trunck.obj", "tree\\treet2.bmp", SuperFolder);

	ysTime.clearEveryFrame = 1;
	ysTime.printStatus = 0; // 0,1,2
}

void YSGL_mainGL()
{
	//cout << YSConst::pi << endl;

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

	for (int i = 0; i < 10; i += 2)
	{
		glPushMatrix();
		{
			glTranslatef(i - 5, 0.2 + xxx, 0);
			glRotatef(theta, 0, 1, 0);
			myHeli.draw();
		}
		glPopMatrix();
	}


	for (int i = 0; i < 10; i++)
	{
		glPushMatrix();
		{
			glTranslatef(i - 5, 0, -5);
			glRotatef(10 * ysSinD(theta), 0, 0, 1);
			myTree.draw();
		}
		glPopMatrix();
	}

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