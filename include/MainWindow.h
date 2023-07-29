#pragma once

#include <wx/frame.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/log.h>
#include <wx/panel.h>


#include <string>


#include "TextBoxs.h"
#include "FunctionButtons.h"



class MainWindow : public wxFrame
{
private:

	wxLog* logger;
	TextBoxs* textBoxsPanel;
	FunctionButtons* buttonsPanel;
	wxBoxSizer* sizer;

public:

	MainWindow(const std::string& title);


	~MainWindow();
};