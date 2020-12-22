#pragma once
#include "functions.h";

class Fraction {
public:
	Fraction();
	Fraction(int get_numerator, int get_denominator);
	Fraction &operator = (const char* str);
	Fraction operator + (Fraction b);
	Fraction operator - (Fraction b);
	friend Fraction operator + (Fraction a, int num);
	friend Fraction operator + (int num, Fraction a);
	friend Fraction operator - (Fraction a, int num);
	friend Fraction operator - (int num, Fraction a);
	operator float();
	static int count;
	void set(int get_numerator, int get_denominator);
	void add(Fraction b);
	void subtract(Fraction b);
	void multiply(Fraction b);
	void divide(Fraction b);
	int getNumerator() { return numerator; };
	int getDenominator() { return denominator; };
	char *getText() { return text; };
private:
	int numerator = NULL;
	int denominator = NULL;
	char* text;
	void reduction();
};