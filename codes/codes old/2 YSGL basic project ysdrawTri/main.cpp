#include "simulation.h"

int YSGL_init_Caller()
{
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);	
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
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
