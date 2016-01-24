#include "RationalNumber.h"

Rational::Rational(): numerator(0), denominator(0), ptr(nullptr)
{ }

Rational::Rational(const Rational & obj): ptr(nullptr)
{
	this->numerator = obj.numerator;
	this->denominator = obj.denominator;
}


Rational::Rational(int a, int b): ptr(nullptr)
{
	if (b == 0)
		throw invalid_argument("Second argument cannot be 0");

	numerator = a;
	denominator = b;
}


string Rational::ToString(bool simplify) const
{
	string output = "";

	if (this -> numerator == 0)
	{
		output = to_string(0);
	}
	else if (simplify)
	{
		auto simplifiedRational = Simplify(numerator, denominator);

		output = to_string(get<0>(simplifiedRational)) + "/" + to_string(get<1>(simplifiedRational));
	}
	else
	{
		output = to_string(numerator) + "/" + to_string(denominator);
	}

	return output;
}


int Rational::FindGreatestCommonDevisor(int a, int b)
{
	return b == 0 ? a : FindGreatestCommonDevisor(b, a % b);
}


tuple<int, int> Rational::Simplify(int a, int b)
{
	auto gcd = FindGreatestCommonDevisor(a, b);

	return make_tuple(a / gcd, b / gcd);
}


Rational::~Rational()
{
}