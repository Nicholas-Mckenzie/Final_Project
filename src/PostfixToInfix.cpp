

#include <stdexcept>


#include "PostfixToInfix.h"


PostfixToInfix::PostfixToInfix(const std::string& input)
	: ExpressionConverter(input)
{
}


void PostfixToInfix::convert()
{
	formatString();

	size_t size = inputStr.size();
	std::string temp;

	for (size_t i = 0; i < size-1; i++)
	{
		char character = inputStr[i];
		char nextChar = inputStr[i+1];

		if (isOperand(character))
		{
			if (character != ' ')
				temp.push_back(character);

			if (nextChar == ' ')
			{
				m_stack.push(temp);
				temp.clear();
			}
				
		}
		else if (isOperator(character))
		{
			if (m_stack.empty())
				throw std::invalid_argument("Invalid Expression");

			rightOperand = m_stack.top();
			m_stack.pop();

			if (m_stack.empty())
				throw std::invalid_argument("Invalid Expression");

			leftOperand = m_stack.top();
			m_stack.pop();
			temp = std::string("( " + leftOperand + " " + character + " " + rightOperand + ")");

			m_stack.push(temp);
			temp.clear();
		}
	}
	if (isOperator(inputStr[size-1]))
	{
		rightOperand = m_stack.top();
		m_stack.pop();
		leftOperand = m_stack.top();
		m_stack.pop();
		m_stack.push(std::string(leftOperand + " " + inputStr[size-1] + " " + rightOperand));
	}

	convertedStr = m_stack.top();
}

void PostfixToInfix::formatString()
{
	if (inputStr.empty())
		return;

	std::string temp;
	size_t size = inputStr.size();

	for (size_t i = 0; i < size-1; i++)
	{
		char character = inputStr[i];
		char nextChar = inputStr[i + 1];

		if (character == ' ')
		{
			if (nextChar != ' ')
				temp.push_back(character);
		}
		else
			temp.push_back(character);

	}
	temp.push_back(inputStr[size - 1]);

	inputStr = temp;
}