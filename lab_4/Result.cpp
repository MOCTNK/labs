#include "Result.h";

Result::Result() : Fraction() {
	result = 1;
}

Result::Result(int numerator, int denominator) : Fraction(numerator, denominator) {
	result = (double)numerator / (double)denominator;
}

Result::Result(Result &a) {
	set(a.getNumerator(), a.getDenominator());
}

Result::Result(Fraction &a) : Fraction(a) {
	result = (double)getNumerator() / (double)getDenominator();
}

Result::Result(Mixed &a) {
	int w = a.getWhole();
	int sign = 1;
	if (w < 0) {
		w *= -1;
		sign = -1;
	}
	set(sign * (w * a.getDenominator() + a.getNumerator()), a.getDenominator());
}

Result &Result::operator = (const char* str) { 
	Fraction::operator=(str);
	result = (double)getNumerator() / (double)getDenominator();
	return *this;
}

Result Result::operator + (Result b) {
	this->add(b);
	return *this;
}

Result Result::operator - (Result b) {
	this->add(b);
	return *this;
}

Result operator + (Result &a, int num) {
	Result b(num, 1);
	a.add(b);
	return a;
}

Result operator + (int num, Result &a) {
	Result b(num, 1);
	a.add(b);
	return a;
}

Result operator - (Result &a, int num) {
	Result b(num, 1);
	a.subtract(b);
	return a;
}

Result operator - (int num, Result &a) {
	Result b(num, 1);
	a.subtract(b);
	return a;
}


void Result::set(int numerator, int denominator) {
	Fraction::set(numerator, denominator);
	result = (double)numerator / (double)denominator;
}

void Result::add(Result b) {
	Fraction::add(b);
	result = (double)getNumerator() / (double)getDenominator();
}

void Result::subtract(Result b) {
	Fraction::subtract(b);
	result = (double)getNumerator() / (double)getDenominator();
}

void Result::multiply(Result b) {
	Fraction::multiply(b);
	result = (double)getNumerator() / (double)getDenominator();
}

void Result::divide(Result b) {
	Fraction::divide(b);
	result = (double)getNumerator() / (double)getDenominator();
}