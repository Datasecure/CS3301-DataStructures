#include "ExpressionNotationConverter.h"


bool ExpressionNotationConverter::IsOperator(char c)
{
	bool value;

	switch (c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '^':
		case '%':
			value = true;
			break;
		default:
			value = false;
			break;
	}
	return value;
}

ExpressionNotationConverter::ExpressionNotationConverter()
{
}

ExpressionNotationConverter::~ExpressionNotationConverter()
{
}


string ExpressionNotationConverter::ConvertInfixToPostfix(string expression)
{
	Stack stack;
	string str = "";

	for (int i = 0; i < expression.length(); i++)
	{
		auto c = expression[i];

		if (IsOperator(c))
		{
			stack.Push(expression[i]);
		}
		else
		{
			str += string(1, c) + " ";
		}
	}

	auto stackCount = stack.Count();

	for (int i = 0; i < stackCount; i++)
	{
		auto c = char(stack.Pop());

		str = str + c;
	}

	return str;
}
