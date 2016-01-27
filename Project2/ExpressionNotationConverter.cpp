#include "ExpressionNotationConverter.h"

int ExpressionNotationConverter::DeterminePrecidence(char c)
{
	auto precedence = -1;

	switch (c)
	{
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

		if (c == '(')
		{
			stack.Push(c);
		}
		else if (c ==')')
		{
			while (!stack.IsEmpty() && stack.Peek() != '(')
			{
				auto operand = stack.Pop();
				
				if (operand != '(' && operand != ')')
				{
					str += string(1, operand) + " ";
				}
			}

			stack.Pop();
		}
		else if (currPrecedence == OPERAND)
		{
			str += string(1, c) + " ";
		}
		else
		{
			while (!stack.IsEmpty() && currPrecedence <= DeterminePrecidence(stack.Peek()))
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

		if (c == '(' || c == ')')
		{
			str = "Invalid Expression!";

			break;
		}
		else
		{
			str += string(1, c) + " ";
		}
	}

	return str;
}
