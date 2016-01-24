#include <iostream>
#include "RationalNumber.h"

using namespace std;

int main()
{
	Rational number1(3, 8);
	Rational number2(1, 6);
	Rational number3(1, 2);
	Rational number4(2, 5);

	auto add = number1 + number2;
	auto sub = number3 - number2;
	auto mult = number1 - number4;
	auto div = number1 / number2;

	cout << add.ToString() << endl;
	cout << sub.ToString() << endl;
	cout << mult.ToString() << endl;
	cout << div.ToString() << endl;

	Rational x;

	cout << x.ToString() << endl;

	Rational y(4, 5);

	cout << y.ToString() << endl;

	auto z = y;

	cout << z.ToString() << endl;

	cin.get();

	return 0;
}