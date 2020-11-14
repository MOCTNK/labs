#include "Result.h";

Result::Result() : Fraction() {
	result = getText();
}

Result::Result(int numerator, int denominator) : Fraction(numerator, denominator) {
	result = getText();
}

Result::Result(Result &a) {
	set(a.getNumerator(), a.getDenominator());
}

Result::Result(Fraction &a) : Fraction(a) {
	result = getText();
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


Result &Result::operator + (Result b) {
	this->add(b);
	return *this;
}

Result &Result::operator - (Result b) {
	this->add(b);
	return *this;
}

Result &operator + (Result &a, int num) {
	Result b(num, 1);
	a.add(b);
	return a;
}

Result &operator + (int num, Result &a) {
	Result b(num, 1);
	a.add(b);
	return a;
}

Result &operator - (Result &a, int num) {
	Result b(num, 1);
	a.subtract(b);
	return a;
}

Result &operator - (int num, Result &a) {
	Result b(num, 1);
	a.subtract(b);
	return a;
}


void Result::set(int numerator, int denominator) {
	Fraction::set(numerator, denominator);
	result = getText();
}

void Result::add(Result b) {
	Result a;
	a.set((getNumerator() * b.getDenominator()) + (getDenominator() * b.getNumerator()),
		  getDenominator() * b.getDenominator());
	result = a.getText();
}

void Result::subtract(Result b) {
	Result a;
	a.set((getNumerator() * b.getDenominator()) - (getDenominator() * b.getNumerator()),
		getDenominator() * b.getDenominator());
	result = a.getText();
}

void Result::multiply(Result b) {
	Result a;
	a.set(getNumerator() * b.getNumerator(), getDenominator() * b.getDenominator());
	result = a.getText();
}

void Result::divide(Result b) {
	Result a;
	a.set(getNumerator() * b.getDenominator(), getDenominator() * b.getNumerator());
	result = a.getText();
}