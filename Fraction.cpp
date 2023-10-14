// Chad Huntebrinker
// crh92d@umsystem.edu
// 11/5/20
// CS201L Lab 11

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD(int num1, int num2)
{
	int remainder = num2 % num1;
	if (remainder != 0)
		return getGCD(remainder, num1);
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
	// Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;

	if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator < 0)) {
		numerator = 0 - numerator;
		denominator = 0 - denominator;
	}
}

//Default Constructor
Fraction::Fraction() {
	numerator = 0;
	denominator = 0;
}

//Overloaded input stream operator
istream& operator>> (istream& input, Fraction& fract) {
	char slash;
	input >> fract.numerator >> slash >> fract.denominator;
	return input;
}

//Overloaded output stream operator
ostream& operator<< (ostream& output, const Fraction& fract) {
	output << fract.numerator << "/" << fract.denominator;
	return output;
}

//An addition operator.  The two denominators multiply each other and that is the final
//denominator.  For the numerators, the numerators are multiplied by the other fraction's
//denominator, then they are added to each other.  Lastly, the final fraction (called temp) is 
//reduced via the reduce function.  Then, temp is returned.
const Fraction Fraction::operator+(const Fraction& rhs) {
	Fraction temp;

	temp.denominator = denominator * rhs.denominator;
	temp.numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);
	temp.reduce();
	return temp;
}

//A subtraction operator.  The two denominators multiply each other and that is the final
//denominator.  For the numerators, the numerators are multiplied by the other fraction's
//denominator, then they are subtracted.  Lastly, the fianl fraction (called temp)
//is reduced via the reduce function.  Then, temp is returned.
const Fraction Fraction::operator-(const Fraction& rhs) {
	Fraction temp;

	temp.denominator = denominator * rhs.denominator;
	temp.numerator = (numerator * rhs.denominator) - (rhs.numerator * denominator);
	temp.reduce();
	return temp;
}

//A multiply operator.  The denominators are multiplied together and that is the
//final denominator.  Then, the numerators are multiplied together.  Finally, the fraction
//is reduced and the final fraction called temp is returned.
const Fraction Fraction::operator*(const Fraction& rhs) {
	Fraction temp;

	temp.denominator = denominator * rhs.denominator;
	temp.numerator = numerator * rhs.numerator;
	temp.reduce();
	return temp;
}

//A division operator.  The first fraction's denominator is divided into the second fraction's
//denominator. The same process is done to the numerator and then the fraction is reduced.
//Finally, the final fraction called temp is returned.
const Fraction Fraction::operator/(const Fraction& rhs) {
	Fraction temp;

	temp.denominator = denominator / rhs.denominator;
	temp.numerator = numerator / rhs.numerator;
	temp.reduce();
	return temp;
}

//A equivalence operator.  The fractions' are reduced first. Then, the
//denominators and numerators are compared to each other and if both fractions' numerators
//and denominators are equal to each other, then true is returned.  Otherwise, false is returned.
bool Fraction::operator==(Fraction rhs) {
	this->reduce();
	rhs.reduce();
	if (denominator == rhs.denominator && numerator == rhs.numerator) {
		return true;
	}
	else {
		return false;
	}
}