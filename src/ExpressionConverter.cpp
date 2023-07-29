

#include "ExpressionConverter.h"


ExpressionConverter::ExpressionConverter(const std::string& input)
	: inputStr(input)
{
}

const std::string& ExpressionConverter::getInputStr() const
{
	return inputStr;
}

const std::string& ExpressionConverter::getConvertedStr() const
{
	return convertedStr;
}

void ExpressionConverter::formatString()
{
	if (inputStr.empty())
		return;

	std::string temp;

	for (char character : inputStr)
	{
		if (character != ' ')
			temp.push_back(character);
	}

	for (size_t i = 1; i < temp.size()-1; i++)
	{
		if (isOperator(temp[i]))
		{
			temp.insert(i, " ");
			temp.insert(i + 2, " ");
			i += 2;
		}
	}

	inputStr = temp;
}

bool ExpressionConverter::balancedParentheses() const
{
	std::stack<char> parentheses;

	for (char character : inputStr)
	{
		if (isOpenParenthese(character))
			parentheses.push(character);
		else if (isClosingParenthese(character))
		{
			if (parentheses.empty())
				return false;
			else if (isBalancedPair(parentheses.top(), character))
				parentheses.pop();
			else
				return false;
		}
	}

	return parentheses.empty();
}

bool ExpressionConverter::isOpenParenthese(char character)
{
	char openPar[3] = { '(','[','{' };

	for (char temp : openPar)
	{
		if (character == temp)
			return true;
	}

	return false;
}

bool ExpressionConverter::isClosingParenthese(char character)
{
	char closePar[3] = { ')', ']', '}' };

	for (char temp : closePar)
	{
		if (character == temp)
			return true;
	}

	return false;
}

bool ExpressionConverter::isParenthese(char character)
{
	if (isOpenParenthese(character) || isClosingParenthese(character))
		return true;

	return false;
}

bool ExpressionConverter::isOperand(char input)
{
	if (isParenthese(input) || isOperator(input))
		return false;

	return true;
}

bool ExpressionConverter::isOperator(char oper)
{
	char operators[5] = { '+','-','*','/','%' };

	for (char element : operators)
		if (element == oper)
			return true;

	return false;
}

int ExpressionConverter::operatorPrecedence(char oper)
{
	if (oper == '%' || oper == '/' || oper == '*')
		return 2;
	else if (oper == '+' || oper == '-')
		return 1;

	return 0;
}

bool ExpressionConverter::isBalancedPair(char openPar, char closePar)
{
	if (openPar == '(' && closePar == ')')
		return true;
	else if (openPar == '[' && closePar == ']')
		return true;
	else if (openPar == '{' && closePar == '}')
		return true;

	return false;
}