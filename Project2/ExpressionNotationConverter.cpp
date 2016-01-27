#include <cmath>
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

int ExpressionNotationConverter::ApplyOperation(char cOperator, int lhs, int rhs)
{
	int result;

	switch (cOperator)
	{
	case '+':
		result = lhs + rhs;
		break;
	case '-':
		result = lhs - rhs;
		break;
	case '*':
		result = lhs * rhs;
		break;
	case '/':
		if (rhs == 0)
			throw logic_error("Invalid expression. Division by zero.");

		result = lhs / rhs;
		break;
	case '%':
		if (rhs == 0)
			throw logic_error("Invalid expression. Division by zero.");

		result = lhs % rhs;
		break;
	case '^':
		result = pow(lhs, rhs);
		break;
	default:
		throw logic_error("Unsupported operator");
		break;
	}

	return result;
}

string ExpressionNotationConverter::ConvertInfixToPostfix(string expression)
{
	Stack operatorStack;
	Stack operandStack;
	string str = "";
	string::size_type strSize;

	for (int i = 0; i < expression.length(); i++)
	{
		auto character = expression[i];
		auto currentCharacterPrecedence = DeterminePrecidence(character);

		if (character == '(')
		{
			operatorStack.Push(character);
		}
		else if (character ==')')
		{
			while (!operatorStack.IsEmpty() && operatorStack.Peek() != '(')
			{
				auto currentOperator = operatorStack.Pop();				
				auto lhs = operandStack.Pop();
				auto rhs = operandStack.Pop();

				operandStack.Push(ApplyOperation(currentOperator, lhs, rhs));
				
				if (currentOperator != '(' && currentOperator != ')')
				{
					str += string(1, currentOperator) + " ";
				}
			}

			operatorStack.Pop();
		}
		else if (currentCharacterPrecedence == OPERAND)
		{
			auto characterAsInt = stoi(string(1, character), &strSize, 10);

			operandStack.Push(characterAsInt);
			str += string(1, character) + " ";
		}
		else
		{
			while (!operatorStack.IsEmpty() && currentCharacterPrecedence <= DeterminePrecidence(operatorStack.Peek()))
			{
				auto currentOperator = operatorStack.Pop();

				if (currentOperator != '(' && currentOperator != ')')
				{					
					auto lhs = operandStack.Pop();
					auto rhs = operandStack.Pop();

					operandStack.Push(ApplyOperation(currentOperator, lhs, rhs));

					str += string(1, currentOperator) + " ";
				}
			}

			operatorStack.Push(character);
		}
	}

	while (!operatorStack.IsEmpty())
	{
		auto currentOperator = operatorStack.Pop();
		auto lhs = operandStack.Pop();
		auto rhs = operandStack.Pop();

		if (currentOperator == '(' || currentOperator == ')')
		{
			str = "Invalid Expression!";

			break;
		}
		else
		{
			operandStack.Push(ApplyOperation(currentOperator, lhs, rhs));

			str += string(1, currentOperator) + " ";
		}
	}

	if (str == "Invalid Expression!")
		return str;

	auto result = operandStack.Pop();

	return str += " : " + to_string(result);
}
