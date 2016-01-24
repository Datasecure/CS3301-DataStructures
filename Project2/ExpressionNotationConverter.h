#pragma once
#include <string>
#include "Stack.h"

using namespace std;

class ExpressionNotationConverter
{
private:
	static bool IsOperator(char c);
public:
	//Constructors
	ExpressionNotationConverter();
	virtual ~ExpressionNotationConverter();

	//Members
	static string ConvertInfixToPostfix(string expression);
};

