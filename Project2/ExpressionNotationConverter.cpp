#include "ExpressionNotationConverter.h"

int ExpressionNotationConverter::DeterminePrecidence(char c)
{
	auto precedence = -1;

	switch (c)
	{
	case '(':
		precedence = 0;
		break;
	case '+':
	case '-':
		precedence = 1;
		break;
	case '*':
	case '/':
	case '%':
		precedence = 2;
		break;
	case '^':
		precedence = 3;
		break;
	case ')':
		precedence = 4;
		break;
	default:
		precedence = -1;
		break;
	}

	return precedence;
}


string ExpressionNotationConverter::ConvertInfixToPostfix(string expression)
{
	Stack stack;
	string str = "";

	for (int i = 0; i < expression.length(); i++)
	{
		auto c = expression[i];
		auto currPrecedence = DeterminePrecidence(c);

		if (currPrecedence == OPERAND)
		{
			str += string(1, c) + " ";
		}
		else if (c == '(')
		{
			stack.Push(c);
		}
		else if (c ==')')
		{
			while (!stack.IsEmpty() && stack.Peek() != 0)
			{
				auto operand = stack.Pop();
				
				if (operand != '(' && operand != ')')
				{
					str += string(1, operand) + " ";
				}
			}
		}
		else
		{
			while (!stack.IsEmpty() && stack.Peek() != 0 && DeterminePrecidence(stack.Peek()) >= currPrecedence)
			{
				auto operand = stack.Pop();
				if (operand != '(' && operand != ')')
				{
					str += string(1, operand) + " ";
				}
			}

			stack.Push(c);
		}
	}

	while (!stack.IsEmpty())
	{
		auto c = char(stack.Pop());

		if (c != '(' && c != ')')
		{
			str += string(1, c) + " ";
		}
	}

	return str;
}
