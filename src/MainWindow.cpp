

#include "MainWindow.h"


MainWindow::MainWindow(const std::string& title)
	: wxFrame(nullptr, wxID_ANY, "This is my test window", wxDefaultPosition, { 600, 600 })
{
#ifdef _DEBUG
	logger = new wxLogWindow(nullptr, "Log");
#endif
	textBoxsPanel = new TextBoxs(this);
	buttonsPanel = new FunctionButtons(this, textBoxsPanel);
	sizer = new wxBoxSizer(wxVERTICAL);

	// Adds buttons and text box to correct sizer
	sizer->Add(textBoxsPanel, 1, wxEXPAND);
	sizer->Add(buttonsPanel, 1, wxEXPAND);

	// Sets the sizer for the window and panel
	this->SetSizerAndFit(sizer);	

}


MainWindow::~MainWindow()
{
	wxLog::SetActiveTarget(nullptr);
	delete logger;
}