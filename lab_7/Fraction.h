#pragma once
#include "functions.h";

class Fraction {
public:
	Fraction();
	Fraction(int get_numerator, int get_denominator);
	static int count;
	void set(int get_numerator, int get_denominator);
	Fraction &operator = (Fraction &a);
	friend bool operator == (Fraction &a, Fraction &b);
	friend std::ostream &operator << (std::ostream &out, Fraction a);
	void add(Fraction b);
	void subtract(Fraction b);
	void multiply(Fraction b);
	void divide(Fraction b);
	int getNumerator() { return numerator; }
	int getDenominator() { return denominator; }
	char *getText() { return text; }
private:
	int numerator;
	int denominator;
	char* text;
	void reduction();
};