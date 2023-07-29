#pragma once


#include <wx/frame.h>
#include <wx/app.h>

#include "MainWindow.h"



class Application : public wxApp
{
public:

	Application();

	virtual bool OnInit();

private:
	MainWindow* window = nullptr;

};


wxIMPLEMENT_APP(Application);



