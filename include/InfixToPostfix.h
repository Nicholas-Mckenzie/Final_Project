#pragma once

#include <string>

#include "ExpressionConverter.h"


class InfixToPostfix : public ExpressionConverter
{
public:
	
	InfixToPostfix(const std::string& input);

	// Converts the given input to a postfix expression
	void convert();

private:

	// Process the mathmatical opreator or parentheses
	void processOperator(char oper);
};