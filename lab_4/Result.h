#pragma once
#include "Fraction.h";
#include "Mixed.h";

class Result : public Fraction {
public:
	Result();
	Result(int numerator, int denominator);
	Result(Result &a);
	Result(Fraction &a);
	Result(Mixed &a);
	Result &operator = (const char* str);
	Result operator + (Result b);
	Result operator - (Result b);
	friend Result operator + (Result &a, int num);
	friend Result operator + (int num, Result &a);
	friend Result operator - (Result &a, int num);
	friend Result operator - (int num, Result &a);
	void set(int numerator, int denominator);
	void add(Result a);
	void subtract(Result b);
	void multiply(Result b);
	void divide(Result b);
	double getResult() { return result; };
private:
	double result;
};