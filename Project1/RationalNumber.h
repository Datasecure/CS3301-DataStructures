#pragma once
#include <string>
#include <tuple>

using namespace std;

class RationalNumber
{

private:
	//Fields
	int numerator;
	int denominator;
	int *ptr;	

public:
	//Constructors
	RationalNumber();
	RationalNumber(const RationalNumber& obj);
	RationalNumber(int a, int b);	
	virtual ~RationalNumber();
	
	//Members
	string ToString(bool simplify = true);

	//Properties
	int GetNumerator() { return numerator; }
	int GetDenominator() { return denominator; }

	//Operator Overloads
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

	//Class Functions
	static int FindGreatestCommonDevisor(int a, int b);
	static tuple<int, int> Simplify(int a, int b);
	
};

