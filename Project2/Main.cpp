#include <iostream>
#include "ExpressionNotationConverter.h"

using namespace std;

int main()
{
	cout << ExpressionNotationConverter::ConvertInfixToPostfix("3+7") << endl;
	cout << ExpressionNotationConverter::ConvertInfixToPostfix("3+7*2") << endl;
	cout << ExpressionNotationConverter::ConvertInfixToPostfix("(3+7)*2") << endl;
	cout << ExpressionNotationConverter::ConvertInfixToPostfix("3+(7-2)*((5-8)") << endl;
	cout << ExpressionNotationConverter::ConvertInfixToPostfix("3+((7*(2-4)+5)*2+9)*(4-8)-10") << endl;

	cin.get();

	return 0;
}