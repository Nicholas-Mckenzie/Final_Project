

#include <wx/log.h>

#include <stdexcept>

#include "FunctionButtons.h"
#include "MyLog.h"
#include "ExpressionConverter.h"
#include "InfixToPostfix.h"
#include "InfixToPrefix.h"
#include "PostfixToInfix.h"


FunctionButtons::FunctionButtons(wxWindow* parent, TextBoxs* textBoxs)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(500, 40)), m_textBoxs(textBoxs)
{
#if _DEBUG
	this->SetBackgroundColour(wxColor(100, 200, 100));
#endif

	buttonSizer = new wxBoxSizer(wxVERTICAL);
	centeringSizer = new wxBoxSizer(wxHORIZONTAL);
	balancedParenthesesButton = new wxButton(this, wxID_ANY, "balance parentheses");
	infixToPostfixButton = new wxButton(this, wxID_ANY, "infix to postfix");
	postfixToInfixButton = new wxButton(this, wxID_ANY, "postfix to infix");
	infixToPrefixButton = new wxButton(this, wxID_ANY, "infix to prefix");

	setLayout();
	setButtonBinds();
}

void FunctionButtons::setLayout()
{
	buttonSizer->Add(centeringSizer, 1, wxALIGN_CENTER);
	centeringSizer->Add(balancedParenthesesButton, 0, wxALIGN_CENTER);
	centeringSizer->Add(infixToPostfixButton, 0, wxALIGN_CENTER);
	centeringSizer->Add(postfixToInfixButton, 0, wxALIGN_CENTER);
	centeringSizer->Add(infixToPrefixButton, 0, wxALIGN_CENTER);


	this->SetSizerAndFit(buttonSizer);
}

void FunctionButtons::setButtonBinds()
{
	balancedParenthesesButton->Bind(wxEVT_BUTTON, &FunctionButtons::balParenthClick, this);
	infixToPostfixButton->Bind(wxEVT_BUTTON, &FunctionButtons::inToPostButtonClick, this);
	postfixToInfixButton->Bind(wxEVT_BUTTON, &FunctionButtons::postToInButtonClick, this);
	infixToPrefixButton->Bind(wxEVT_BUTTON, &FunctionButtons::inToPreButtonClick, this);
}

void FunctionButtons::balParenthClick(wxCommandEvent& event)
{
	ExpressionConverter temp(m_textBoxs->getInput());

	if (temp.balancedParentheses())
		m_textBoxs->setResultLabel("Parentheses are balanced");
	else
		m_textBoxs->setResultLabel("Parentheses are NOT balanced");
}

void FunctionButtons::inToPostButtonClick(wxCommandEvent& event)
{
	LOG("In to Post button clicked");

	InfixToPostfix temp(m_textBoxs->getInput());

	if (temp.balancedParentheses())
	{
		temp.convert();
		
		m_textBoxs->setResultLabel(temp.getConvertedStr());
	}
	else
		//m_textBoxs->setResultLabel("Parentheses are NOT balanced");
		wxLogMessage("Parentheses are NOT balanced");
}

void FunctionButtons::postToInButtonClick(wxCommandEvent& event)
{
	LOG("Post to In button clicked");

	PostfixToInfix temp(m_textBoxs->getInput());

	if (temp.balancedParentheses())
	{
		try
		{
			temp.convert();
		}
		catch (...)
		{
			wxLogMessage("Invalid Expression");
		}

		m_textBoxs->setResultLabel(temp.getConvertedStr());
	}
	else
		//m_textBoxs->setResultLabel("Parentheses are NOT balanced");
		wxLogMessage("Parentheses are NOT balanced");
}

void FunctionButtons::inToPreButtonClick(wxCommandEvent& event)
{
	LOG("In to Pre button clicked");

	InfixToPrefix temp(m_textBoxs->getInput());

	if (temp.balancedParentheses())
	{
		temp.convert();

		m_textBoxs->setResultLabel(temp.getConvertedStr());
	}
	else
		//m_textBoxs->setResultLabel("Parentheses are NOT balanced");
		wxLogMessage("Parentheses are NOT balanced");
}