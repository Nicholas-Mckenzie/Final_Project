#pragma once

#include <wx/window.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/event.h>
#include <wx/button.h>

#include "TextBoxs.h"

class FunctionButtons : public wxPanel
{
private:
	wxBoxSizer* buttonSizer;
	wxBoxSizer* centeringSizer;
	wxButton* balancedParenthesesButton;
	wxButton* infixToPostfixButton;
	wxButton* postfixToInfixButton;
	wxButton* infixToPrefixButton;

	TextBoxs* m_textBoxs;
	//MainWindow* parent;

public:

	FunctionButtons(wxWindow* parent, TextBoxs* textBoxs);

private:

	// Sets up the layout of the buttons to be placed side by side
	void setLayout();

	// Provides the button with functionality
	void setButtonBinds();

	// Called by the Balanced parentheses button
	void balParenthClick(wxCommandEvent& event);

	// Called by the infix to postfix button
	void inToPostButtonClick(wxCommandEvent& event);

	// Called by the postfix to infix button
	void postToInButtonClick(wxCommandEvent& event);

	// Called by the infix to prefix button
	void inToPreButtonClick(wxCommandEvent& event);
};
