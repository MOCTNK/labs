#pragma once;
#include "functions.h";
#include <iostream>;
#include <fstream>;

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
	friend std::ofstream &operator << (std::ofstream &fout, Fraction a);
	friend std::ifstream &operator >> (std::ifstream &fin, Fraction &a);
	friend std::ostream &operator << (std::ostream &out, Fraction a);
	friend std::istream &operator >> (std::istream &in, Fraction &a);
	void write(std::ofstream &fout);
	void read(std::ifstream &fin);
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
	int numerator;
	int denominator;
	char* text;
	void reduction();
};