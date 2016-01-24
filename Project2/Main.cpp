#include <iostream>
#include "ExpressionNotationConverter.h"

using namespace std;

int main()
{

	cout << ExpressionNotationConverter::ConvertInfixToPostfix("3+7") << endl;

	cin.get();

	return 0;
}