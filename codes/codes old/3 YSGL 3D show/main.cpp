#include "simulation.h"

int YSGL_init_Caller()
{
	glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);					// Set The Blending Function For Translucency
	glClearColor(0.5f, 0.5f, 1.0f, 0.0f);				// This Will Clear The Background Color To Black
	glClearDepth(1.0);									// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);								// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glShadeModel(GL_SMOOTH);							// Enables Smooth Color Shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	BuildFont();

	glEnable(GL_COLOR_MATERIAL);
	
	YSGL_init();
	return TRUE;
}


int YSGL_mainGL_Caller()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	myCam.Render();
	YSGL_mainGL();

	return TRUE;
}


int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
				   HINSTANCE	hPrevInstance,		// Previous Instance
				   LPSTR		lpCmdLine,			// Command Line Parameters
				   int			nCmdShow)			// Window Show State
{
	MSG		msg;
	BOOL	done=FALSE;

	if (!CreateGLWindow()) return 0;

	while(!done)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if (msg.message==WM_QUIT)
			{
				done=TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if ((active && !YSGL_mainGL_Caller()) || keys[VK_ESCAPE])
			{
				done=TRUE;
			}
			else
			{
				SwapBuffers(hDC);
				myCam.camKBfunc(keys);
			}
		}
	}
	KillGLWindow();	
	return (msg.wParam);
}
