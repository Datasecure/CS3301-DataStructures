#pragma once
#include <string>
#include <tuple>

using namespace std;

class RationalNumber
{

private:
	int numerator;
	int denominator;

	static tuple<int, int> Simplify(int a, int b);

public:
	RationalNumber(int a, int b);	
	string ToString();

	int GetNumerator() { return numerator; }
	int GetDenominator() { return denominator; }

	virtual ~RationalNumber();

	RationalNumber operator+(const RationalNumber & right)
	{
		int aCrossMultipliedNumerator = this -> numerator * right.denominator;
		int bCrossMultipliedNumerator = right.numerator * this -> denominator;
		int crossMultipledDenominator = this -> denominator * right.denominator;

		RationalNumber rationalNumber((aCrossMultipliedNumerator + bCrossMultipliedNumerator), crossMultipledDenominator);

		return rationalNumber;
	}

	RationalNumber operator-(const RationalNumber & right)
	{
		int aCrossMultipliedNumerator = this->numerator * right.denominator;
		int bCrossMultipliedNumerator = right.numerator * this->denominator;
		int crossMultipledDenominator = this->denominator * right.denominator;

		RationalNumber rationalNumber((aCrossMultipliedNumerator - bCrossMultipliedNumerator), crossMultipledDenominator);

		return rationalNumber;
	}

	RationalNumber operator*(const RationalNumber & right)
	{
		RationalNumber rationalNumber((this -> numerator * right.numerator), (this -> denominator * right.denominator));

		return rationalNumber;
	}

	RationalNumber operator/(const RationalNumber & right)
	{
		RationalNumber rationalNumber((this->numerator * right.denominator), (this->denominator * right.numerator));

		return rationalNumber;
	}

	static int FindGreatestCommonDevisor(int a, int b);
	
protected:
	RationalNumber();
};

