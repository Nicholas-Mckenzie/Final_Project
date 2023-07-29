


#include "InfixToPrefix.h"


InfixToPrefix::InfixToPrefix(const std::string& input)
	: ExpressionConverter(input)
{
}

/* const std::string& InfixToPrefix::getReverseStr() const
{
	return reverseStr;
} */

void InfixToPrefix::convert()
{
	formatString();
	reverseString();

	for (char character : reverseStr)
	{
		if (isClosingParenthese(character))
			operatorStack.push(character);
		else if (isOpenParenthese(character) ||
				 isOperator(character))
			processOperator(character);
		else if (!isOperator(character))
			convertedStr.push_back(character);
	}

	while (!operatorStack.empty())
	{
		convertedStr.push_back(operatorStack.top());
		operatorStack.pop();
	}

	reverseConvertedString();
}

void InfixToPrefix::processOperator(char oper)
{
	if (isOpenParenthese(oper))
	{
		while (!isBalancedPair(oper, operatorStack.top()))
		{
			convertedStr.push_back(operatorStack.top());
			operatorStack.pop();
		}
		operatorStack.pop();
	}
	else if (isOperator(oper))
	{
		if (operatorStack.empty())
			operatorStack.push(oper);
		else if (operatorPrecedence(oper) >= operatorPrecedence(operatorStack.top()))
			operatorStack.push(oper);
		else if (operatorPrecedence(oper) < operatorPrecedence(operatorStack.top()))
		{
			while (!operatorStack.empty() ||
				  (operatorPrecedence(operatorStack.top()) <= operatorPrecedence(oper)))
			{
				convertedStr.push_back(operatorStack.top());
				operatorStack.pop();

				if (operatorStack.empty())
					break;
			}
			operatorStack.push(oper);
		}
	}

}


void InfixToPrefix::reverseString()
{
	size_t size = inputStr.size();

	for (int i = 0; i < size; i++)
	{
		reverseStr.push_back(inputStr[size-i-1]);
	}
}

void InfixToPrefix::reverseConvertedString()
{
	std::string temp;
	size_t size = convertedStr.size();

	for (int i = 0; i < size; i++)
	{
		temp.push_back(convertedStr[size - i - 1]);
	}

	convertedStr = temp;
}

bool InfixToPrefix::isParentheses(char oper)
{
	if (isOpenParenthese(oper) || isClosingParenthese(oper))
		return true;

	return false;
}