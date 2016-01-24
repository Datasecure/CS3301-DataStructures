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
		else
		{
			while (stack.Count() > 0 && DeterminePrecidence(stack.Peek()) >= currPrecedence)
			{
				auto operand = stack.Pop();

				str += string(1, operand) + " ";
			}

			stack.Push(expression[i]);
		}
	}

	while (!stack.IsEmpty())
	{
		auto c = char(stack.Pop());

		str += string(1, c) + " ";
	}

	return str;
}
