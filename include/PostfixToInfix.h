#pragma once



#include <string>
#include <vector>
#include <stack>


#include "ExpressionConverter.h"



class PostfixToInfix : public ExpressionConverter
{
public:

	PostfixToInfix(const std::string& input);

	// Converts the given input into an infix expression
	void convert();

private:

	// Formats the given string to be converted
	void formatString();

	std::string leftOperand;
	std::string rightOperand;
	std::string currentOperator;
	std::stack<std::string> m_stack;
};
