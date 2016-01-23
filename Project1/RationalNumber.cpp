#include "RationalNumber.h"

RationalNumber::RationalNumber(){}


RationalNumber::RationalNumber(int a, int b)
{
	if (b == 0)
		throw invalid_argument("Second argument cannot be 0");

	numerator = a;
	denominator = b;
}


string RationalNumber::ToString()
{
	tuple<int, int> simplifiedRational = Simplify(numerator, denominator);

	string output = to_string(get<0>(simplifiedRational)) + "/" + to_string(get<1>(simplifiedRational));

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