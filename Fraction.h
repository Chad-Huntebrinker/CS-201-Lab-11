#pragma once
// Chad Huntebrinker
// 11/5/20
// Lab 9

#include <iostream>
using namespace std;

class Fraction
{

	// Add the variables and functions you need to. getGCD and reduce are 
	// provided for you.

private:
	int getGCD(int num1, int num2);
	int numerator;
	int denominator;

public:
	void reduce();
	//Default constructor
	Fraction();

	//Input and output stream operators
	friend istream& operator>> (istream& input, Fraction& fract);
	friend ostream& operator<< (ostream& output, const Fraction& fract);

	//(+), (-), (*), (/) and (==) operators
	const Fraction operator+(const Fraction& rhs);
	const Fraction operator-(const Fraction& rhs);
	const Fraction operator/(const Fraction& rhs);
	const Fraction operator*(const Fraction& rhs);
	bool operator==(Fraction rhs);

};

