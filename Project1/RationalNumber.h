#pragma once
#include <string>
#include <tuple>

using namespace std;

class Rational
{
	//Fields
	int numerator;
	int denominator;
	int *ptr;	

public:
	//Constructors
	Rational();
	Rational(const Rational& obj);
	Rational(int a, int b);	
	virtual ~Rational();
	
	//Members
	string ToString(bool simplify = true) const;

	//Properties
	int GetNumerator() const
	{ return numerator; }

	int GetDenominator() const
	{ return denominator; }

	//Operator Overloads
	Rational operator+(const Rational & right) const
	{
		auto aCrossMultipliedNumerator = this -> numerator * right.denominator;
		auto bCrossMultipliedNumerator = right.numerator * this -> denominator;
		auto crossMultipledDenominator = this -> denominator * right.denominator;

		Rational rationalNumber((aCrossMultipliedNumerator + bCrossMultipliedNumerator), crossMultipledDenominator);

		return rationalNumber;
	}

	Rational operator-(const Rational & right) const
	{
		auto aCrossMultipliedNumerator = this->numerator * right.denominator;
		auto bCrossMultipliedNumerator = right.numerator * this->denominator;
		auto crossMultipledDenominator = this->denominator * right.denominator;

		Rational rationalNumber((aCrossMultipliedNumerator - bCrossMultipliedNumerator), crossMultipledDenominator);

		return rationalNumber;
	}

	Rational operator*(const Rational & right) const
	{
		Rational rationalNumber((this -> numerator * right.numerator), (this -> denominator * right.denominator));

		return rationalNumber;
	}

	Rational operator/(const Rational & right) const
	{
		Rational rationalNumber((this->numerator * right.denominator), (this->denominator * right.numerator));

		return rationalNumber;
	}

	//Class Functions
	static int FindGreatestCommonDevisor(int a, int b);
	static tuple<int, int> Simplify(int a, int b);
	
};

