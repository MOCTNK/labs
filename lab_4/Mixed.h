#pragma once
#include "Fraction.h";

class Mixed : public Fraction {
public:
	Mixed();
	Mixed(int wh, int numerator, int denominator);
	Mixed(Mixed &a);
	Mixed(Fraction &a);
	Mixed &operator = (const char* str);
	Mixed operator + (Mixed b);
	Mixed operator - (Mixed b);
	friend Mixed operator + (Mixed a, int num);
	friend Mixed operator + (int num, Mixed a);
	friend Mixed operator - (Mixed a, int num);
	friend Mixed operator - (int num, Mixed a);
	friend std::ofstream &operator << (std::ofstream &fout, Mixed a);
	friend std::ifstream &operator >> (std::ifstream &fin, Mixed &a);
	friend std::ostream &operator << (std::ostream &out, Mixed a);
	friend std::istream &operator >> (std::istream &in, Mixed &a);
	void read(std::ifstream &fin);
	void set(int wh, int numerator, int denominator);
	void add(Mixed a);
	void subtract(Mixed b);
	void multiply(Mixed b);
	void divide(Mixed b);
	char *getText();
	int getWhole() { return whole; };
	char *toFraction();
private:
	int whole;
};