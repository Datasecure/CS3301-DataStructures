#include <iostream>
#include "RationalNumber.h"

using namespace std;

int main()
{
	RationalNumber number1(2, 4);
	RationalNumber number2(3, 7);

	cout << number1.ToString() << endl;
	cout << number2.ToString() << endl;

	RationalNumber add = number1 + number2;
	RationalNumber mult = number1 * number2;
	RationalNumber sub = number1 - number2;
	RationalNumber div = number1 / number2;

	cout << add.ToString() << endl;
	cout << mult.ToString() << endl;
	cout << sub.ToString() << endl;
	cout << div.ToString() << endl;

	cin.get();

	return 0;
}