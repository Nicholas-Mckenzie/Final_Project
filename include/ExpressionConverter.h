#pragma once

#include <string>
#include <stack>

class ExpressionConverter
{
protected:
	std::string inputStr;
	std::string convertedStr;
	std::stack<char> operatorStack;

	void formatString();

public:

	ExpressionConverter(const std::string& input);
	
	const std::string& getInputStr() const;

	const std::string& getConvertedStr() const;

	// Checks if a string has a balanced number of parentheses
	bool balancedParentheses() const;

	// Checks if given character is an open parentheses
	static bool isOpenParenthese(char character);

	// Checks if given character is an open parentheses
	static bool isClosingParenthese(char character);

	// Checks if given character is a parenthese
	static bool isParenthese(char character);

	// Checks if a given character is an operator i.e { +, -, *, /, % }
	static bool isOperator(char oper);

	// Checks to see if the input is not a parentheses or operator
	static bool isOperand(char input);

	// Returns 1 for +/-, 2 for %/* or /, 0 otherwise
	static int operatorPrecedence(char oper);

	// Checks to see if the parentheses area a pair ie (), {}, []
	static bool isBalancedPair(char openPar, char closePar); 
};



