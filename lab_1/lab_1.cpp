#include <iostream>
#include "classes.h";
using namespace std;

bool testAdd(Fraction &a, Fraction b, Fraction c) {
	a.add(b);
	if (a.getNumerator() == c.getNumerator() && a.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testSubtract(Fraction &a, Fraction b, Fraction c) {
	a.subtract(b);
	if (a.getNumerator() == c.getNumerator() && a.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testMultiply(Fraction &a, Fraction b, Fraction c) {
	a.multiply(b);
	if (a.getNumerator() == c.getNumerator() && a.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testDivide(Fraction a, Fraction b, Fraction c) {
	a.divide(b);
	if (a.getNumerator() == c.getNumerator() && a.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testSet(int numerator, int denominator, Fraction a) {
	int num = a.count;
	a.set(numerator, denominator);
	if (num != a.count) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	Fraction a(3,5);
	Fraction b(7, 11);
	Fraction c(68, 55);
	cout << a.getText() << " + " << b.getText();
	if (testAdd(a, b, c) == true) {
		cout << " = " << c.getText() << endl;
		cout << "Fraction addition test completed successfully" << endl;
	}
	else {
		cout << " != " << c.getText() << endl;
		cout << "Fraction addition test completed failed" << endl;
	}
	cout << endl;

	a.set(-5, 7);
	b.set(20, 21);
	c.set(-5, 3);
	cout << a.getText() << " - " << b.getText();
	if (testSubtract(a, b, c) == true) {
		cout << " = " << c.getText() << endl;
		cout << "Fraction subtraction test completed successfully" << endl;
	}
	else {
		cout << " != " << c.getText();
		cout << "Fraction subtraction test completed failed" << endl;
	}
	cout << endl;

	a.set(2, 9);
	b.set(27, 34);
	c.set(3, 17);
	cout << a.getText() << " * " << b.getText();
	if (testMultiply(a, b, c) == true) {
		cout << " = " << c.getText() << endl;
		cout << "Fraction multiplication test completed successfully" << endl;
	}
	else {
		cout << " != " << c.getText() << endl;
		cout << "Fraction multiplication test completed failed" << endl;
	}
	cout << endl;

	a.set(56, 75);
	b.set(-45, 34);
	c.set(-1904, 3375);
	cout << a.getText() << " : " << b.getText();
	if (testDivide(a, b, c) == true) {
		cout << " = " << c.getText() << endl;
		cout << "Fraction division test completed successfully" << endl;
	}
	else {
		cout << " != " << c.getText() << endl;
		cout << "Fraction division test completed failed" << endl;
	}
	cout << endl;

	cout << "Fraction 23/0 is";
	if (testSet(23, 0, a) == true) {
		cout << " set " << a.getText() << endl;
		cout << "Set fraction test completed successfully" << endl;
	}
	else {
		cout << " not set. Error! The denominator is zero" << endl;
		cout << "Set fraction test completed failed" << endl;
	}
	cout << endl;

	cout << "Fraction 34/60 is";
	if (testSet(34, 60, a) == true) {
		cout << " set " << endl;
		cout << "Set fraction test completed successfully" << endl;
	}
	else {
		cout << " not set. Error! The denominator is zero" << endl;
		cout << "Set fraction test completed failed" << endl;
	}
	cout << endl;

	cout << Fraction::count << " fractions were initialized" <<endl;
	return 0;
}