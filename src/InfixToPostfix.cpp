

#include <stdexcept>

#include "InfixToPostfix.h"


InfixToPostfix::InfixToPostfix(const std::string& input)
	: ExpressionConverter(input)
{
}

void InfixToPostfix::convert()
{
	formatString();

	for (char currentChar : inputStr)
	{
		if (isOpenParenthese(currentChar) ||
			isClosingParenthese(currentChar))
		{
			processOperator(currentChar);
		}
		else if (!isOperator(currentChar))
			convertedStr.push_back(currentChar);
		else if (isOperator(currentChar))
			processOperator(currentChar);
		else
			throw std::invalid_argument("Invalid Expression");
	}

	while (!operatorStack.empty())
	{
		convertedStr.push_back(operatorStack.top());
		operatorStack.pop();
	}
}

void InfixToPostfix::processOperator(char oper)
{
	if (operatorStack.empty() || isOpenParenthese(oper))
	{
		operatorStack.push(oper);
	}
	else if (isClosingParenthese(oper))
	{
		while (!operatorStack.empty() &&
			!isOpenParenthese(operatorStack.top()) &&
			operatorPrecedence(oper) <= operatorPrecedence(operatorStack.top()))
		{
			convertedStr.push_back(' ');
			convertedStr.push_back(operatorStack.top());
			operatorStack.pop();
		}

		if (isClosingParenthese(oper))
		{
			if (!operatorStack.empty() && isOpenParenthese(operatorStack.top()))
			{
				operatorStack.pop();
			}
		}
	}
	else if (operatorPrecedence(oper) > operatorPrecedence(operatorStack.top()))
		operatorStack.push(oper);
	else
	{
		while (!operatorStack.empty() &&
			operatorPrecedence(oper) <= operatorPrecedence(operatorStack.top()))
		{
			convertedStr.push_back(' ');
			convertedStr.push_back(operatorStack.top());
			operatorStack.pop();
		}
		operatorStack.push(oper);
	}
}