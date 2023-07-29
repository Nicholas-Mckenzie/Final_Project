


#include "TextBoxs.h"
#include "MyLog.h"

TextBoxs::TextBoxs(wxWindow* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(300,20))
{
#if _DEBUG
	this->SetBackgroundColour(wxColor(100, 100, 200));
#endif

	verticalBoxSizer = new wxBoxSizer(wxVERTICAL);

	inputBox = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, {300, 20});
	inputLabel = new wxStaticText(this, wxID_ANY, "Input: ");
	inputBoxSizer = new wxBoxSizer(wxHORIZONTAL);
	inputBox->SetMaxLength(60);

	resultTextBox = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, { 300, 20 }, wxTE_READONLY);
	resultBoxLabel = new wxStaticText(this, wxID_ANY, "Result: ");
	resultBoxSizer = new wxBoxSizer(wxHORIZONTAL);

	setLayout();
}


void TextBoxs::setLayout()
{
	verticalBoxSizer->Add(inputBoxSizer, 0, wxALIGN_CENTER | wxBOTTOM, 10);
	verticalBoxSizer->Add(resultBoxSizer, 0, wxALIGN_CENTER);

	inputBoxSizer->Add(inputLabel, 0, wxRIGHT, 10);
	inputBoxSizer->Add(inputBox, 1, wxEXPAND);

	resultBoxSizer->Add(resultBoxLabel, 0, wxRIGHT, 10);
	resultBoxSizer->Add(resultTextBox, 1, wxEXPAND);

	this->SetSizerAndFit(verticalBoxSizer);
}

std::string TextBoxs::getInput() const
{
	return inputBox->GetValue().ToStdString();
}

void TextBoxs::setResultLabel(const std::string& str)
{
	resultTextBox->SetLabel(str);
}
