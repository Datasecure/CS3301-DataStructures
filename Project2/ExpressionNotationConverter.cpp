#include <cmath>
#include "ExpressionNotationConverter.h"
#include <iostream>

int ExpressionNotationConverter::DeterminePrecidence(string str)
{
	if (str == "+" || str == "-") return 1;
	if (str == "*" || str == "/" || str == "%") return 2;
	if (str == "^") return 3;

	for (unsigned i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			logic_error("An unsupported operator or invalid number passed.");
	}

	return -1;
}

int ExpressionNotationConverter::ApplyOperation(string sOperator, int lhs, int rhs)
{
	if (sOperator == "+") return lhs + rhs;
	if (sOperator == "-") return lhs - rhs;
	if (sOperator == "*") return lhs * rhs;
	if (sOperator == "^") return pow(lhs, rhs);

	if (sOperator == "/")
	{
		if (rhs == 0)
			throw logic_error("Invalid expression. Division by zero.");
		return lhs / rhs;
	}

	if (sOperator == "%")
	{
		if (rhs == 0)
			throw logic_error("Invalid expression. Division by zero.");
		return lhs % rhs;
	}

	throw logic_error("Unsupported operator.");
}

string ExpressionNotationConverter::ConvertInfixToPostfix(string expression)
{
	Stack operatorStack;
	Stack operandStack;
	string outputString = "";

	auto tmp = expression;

	while (tmp.length() > 0)
	{
		auto strLength = tmp.length();
		auto numberToSkip = 0;
		auto skip = 1;

		do
		{
			auto tmp1 = tmp.substr(numberToSkip, 1);

			if (!isdigit(tmp1[0]))
				break;

			numberToSkip++;
		} while (numberToSkip - 1 < strLength);

		if (numberToSkip > 0)
		{
			skip = numberToSkip;
		}

		auto subString = tmp.substr(0, strLength - (strLength - skip));
		auto currentCharacterPrecedence = DeterminePrecidence(subString);

		if (subString == "(")
		{
			operatorStack.Push(subString);
		}
		else if (subString == ")")
		{
			while (!operatorStack.IsEmpty() && operatorStack.Peek() != "(")
			{
				auto currentOperator = operatorStack.Pop();
				auto lhs = stoi(operandStack.Pop());
				auto rhs = stoi(operandStack.Pop());
				auto result = to_string(ApplyOperation(currentOperator, lhs, rhs));

				/*cout << to_string(lhs) + currentOperator + to_string(rhs) + " = " + result << endl;*/

				operandStack.Push(result);

				if (currentOperator != "(" && currentOperator != ")")
				{
					outputString += currentOperator + " ";
				}
			}

			auto paren = operatorStack.Pop();
		}
		else if (currentCharacterPrecedence == OPERAND)
		{
			operandStack.Push(subString);

			outputString += subString + " ";
		}
		else
		{
			while (!operatorStack.IsEmpty() && currentCharacterPrecedence <= DeterminePrecidence(operatorStack.Peek()))
			{
				auto currentOperator = operatorStack.Pop();

				outputString += currentOperator + " ";

				if (currentOperator != "(" && currentOperator != ")")
				{
					auto lhs = stoi(operandStack.Pop());
					auto rhs = stoi(operandStack.Pop());
					auto result = to_string(ApplyOperation(currentOperator, lhs, rhs));

					/*cout << to_string(lhs) + currentOperator + to_string(rhs) + " = " + result << endl;*/

					operandStack.Push(result);
				}
			}

			operatorStack.Push(subString);
		}

		tmp = string(tmp.substr(skip));
	}

	while (!operatorStack.IsEmpty())
	{
		auto currentOperator = operatorStack.Pop();

		if (currentOperator == "(" || currentOperator == ")")
		{
			outputString = "Invalid Expression!";

			break;
		}

		auto lhs = stoi(operandStack.Pop());
		auto rhs = stoi(operandStack.Pop());
		auto result = to_string(ApplyOperation(currentOperator, lhs, rhs));

		/*cout << to_string(lhs) + currentOperator + to_string(rhs) + " = " + result << endl;*/

		operandStack.Push(result);

		outputString += currentOperator + " ";
	}

	if (outputString == "Invalid Expression!")
	{
		return outputString;
	}

	auto result = operandStack.Pop();

	return outputString += " : " + result;
}
