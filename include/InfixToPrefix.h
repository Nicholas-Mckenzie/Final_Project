#pragma once

#include <string>

#include "ExpressionConverter.h"


class InfixToPrefix : public ExpressionConverter
{
private:
	std::string reverseStr;

public:
	
	InfixToPrefix(const std::string& input);

	// Converts the given input to a prefix expression
	void convert();


private:

	// Handles operations for mathmatical operators and parentheses when converting
	void processOperator(char oper);

	// Reverses the given string's order
	void reverseString();

	// Takes the converted reversed infix to prefix string and reverses 
	// giving the complete conversion from Infix to Prefix
	void reverseConvertedString();

	// Checks if the input is a parentheses
	bool isParentheses(char oper);;

};
