#include "RationalNumber.h"

RationalNumber::RationalNumber() { }

RationalNumber::RationalNumber(const RationalNumber & obj)
{
	this->numerator = obj.numerator;
	this->denominator = obj.denominator;
}


RationalNumber::RationalNumber(int a, int b)
{
	if (b == 0)
		throw invalid_argument("Second argument cannot be 0");

	numerator = a;
	denominator = b;
}


string RationalNumber::ToString(bool simplify)
{
	string output = "";

	if (this -> numerator == 0)
	{
		output = to_string(0);
	}
	else if (simplify)
	{
		tuple<int, int> simplifiedRational = Simplify(numerator, denominator);

		output = to_string(get<0>(simplifiedRational)) + "/" + to_string(get<1>(simplifiedRational));
	}
	else
	{
		output = to_string(numerator) + "/" + to_string(denominator);
	}

	return output;
}


int RationalNumber::FindGreatestCommonDevisor(int a, int b)
{
	return b == 0 ? a : FindGreatestCommonDevisor(b, a % b);
}


tuple<int, int> RationalNumber::Simplify(int a, int b)
{
	int gcd = FindGreatestCommonDevisor(a, b);

	return make_tuple(a / gcd, b / gcd);
}


RationalNumber::~RationalNumber()
{
}