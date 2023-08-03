#include "simulation.h"
#include  "YSGL_settings.h"

int YSGL_init_Caller()
{
	glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);					// Set The Blending Function For Translucency
	glClearColor(0.5f, 0.5f, 1.0f, 0.0f);				// This Will Clear The Background Color To Black
	glClearDepth(1.0);									// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);								// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glShadeModel(GL_SMOOTH);							// Enables Smooth Color Shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	BuildFont();

	glEnable(GL_COLOR_MATERIAL);

	ysTime.init();
	YSGL_init();

	
	return TRUE;
}


int YSGL_mainGL_Caller()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	myCam.Render();
	myCam.camKBfunc(keys);
	
	ysTime.update();
	YSGL_mainGL();

	return TRUE;
}
int YSGL_main_entry_point2(){
	return YSGL_main_entry_point(YSGL_scr_width, YSGL_scr_height);
}

#ifdef YSGL_forms

#include "MyForm.h" 
using namespace System;
using namespace System::Windows::Forms;
using namespace YSGL_projectName; // ÷⁄ Â‰« «”„ „‘—Ê⁄ﬂ
[STAThread]
void main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	YSGL_projectName::MyForm form;
	Application::Run(%form);
}

#else

int main(){
	YSGL_main_entry_point2();
}

#endif