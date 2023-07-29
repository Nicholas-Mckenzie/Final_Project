#pragma once



#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/colour.h>

#include <string>

#include "MyLog.h"


class TextBoxs : public wxPanel
{
private:
	wxBoxSizer* verticalBoxSizer;
	wxTextCtrl* inputBox;
	wxStaticText* inputLabel;
	wxBoxSizer* inputBoxSizer;
	wxTextCtrl* resultTextBox;
	wxStaticText* resultBoxLabel;
	wxBoxSizer* resultBoxSizer;

	void setLayout();

public:

	TextBoxs(wxWindow* parent);

	// Returns the User Input from the Input text box
	std::string getInput() const;

	// Sets the characters inside of the Results text box
	void setResultLabel(const std::string& str);
};
