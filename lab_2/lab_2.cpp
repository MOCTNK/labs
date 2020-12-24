#include <iostream>
#include "functions.h"
#include "classes.h"
using namespace std;

bool testAssignmentOperator(Fraction a, const char* str, Fraction b) {
	a = str;
	if (a.getNumerator() == b.getNumerator() && a.getDenominator() == b.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testFractionPlusFraction(Fraction a, Fraction b, Fraction c) {
	a = a + b;
	if (a.getNumerator() == c.getNumerator() && a.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testFractionMinusFraction(Fraction a, Fraction b, Fraction c) {
	a = a - b;
	if (a.getNumerator() == c.getNumerator() && a.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testFractionPlusInt(Fraction a, int num, Fraction c) {
	a = a + num;
	if (a.getNumerator() == c.getNumerator() && a.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testIntPlusFraction(Fraction a, int num, Fraction c) {
	a = num + a;
	if (a.getNumerator() == c.getNumerator() && a.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testFractionMinusInt(Fraction a, int num, Fraction c) {
	a = a - num;
	if (a.getNumerator() == c.getNumerator() && a.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testIntMinusFraction(Fraction a, int num, Fraction c) {
	a = num - a;
	if (a.getNumerator() == c.getNumerator() && a.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testFloatOperator(Fraction a) {
	if ((float)a == (float)a.getNumerator() / (float)a.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	Fraction a;
	Fraction b;
	Fraction c;
	b = "3/5";
	c = "41/35";

	if(testAssignmentOperator(a, "3/5", b)) {
		cout << "a = " << b.getText() << endl;
		cout << "Assignment operator test completed successfully" << endl;
	}
	else {
		cout << "a != " << b.getText() << endl;
		cout << "Assignment operator test completed failed" << endl;
	}
	cout << endl;

	a = "4/7";

	cout << a.getText() << " + " << b.getText();
	if (testFractionPlusFraction(a,b,c)) {
		cout << " = " << c.getText() << endl;
		cout << "Fraction plus Fraction test completed successfully" << endl;
	}
	else {
		cout << " != " << c.getText() << endl;
		cout << "Fraction plus Fraction test completed failed" << endl;
	}
	cout << endl;

	c = "-1/35";
	cout << a.getText() << " - " << b.getText();
	if (testFractionMinusFraction(a, b, c)) {
		cout << " = " << c.getText() << endl;
		cout << "Fraction minus Fraction test completed successfully" << endl;
	}
	else {
		cout << " != " << c.getText() << endl;
		cout << "Fraction minu Fraction test completed failed" << endl;
	}
	cout << endl;

	int num = 23;
	c = "165/7";
	
	cout << a.getText() << " + " << num;
	if (testFractionPlusInt(a, num, c)) {
		cout << " = " << c.getText() << endl;
		cout << "Fraction plus Int test completed successfully" << endl;
	}
	else {
		cout << " != " << c.getText() << endl;
		cout << "Fraction plus Int test completed failed" << endl;
	}
	cout << endl;

	cout << num << " + " << a.getText();
	if (testFractionPlusInt(a, num, c)) {
		cout << " = " << c.getText() << endl;
		cout << "Int plus Fraction test completed successfully" << endl;
	}
	else {
		cout << " != " << c.getText() << endl;
		cout << "Int plus Fraction test completed failed" << endl;
	}
	cout << endl;

	c = "-157/7";
	cout << a.getText() << " - " << num;
	if (testFractionMinusInt(a, num, c)) {
		cout << " = " << c.getText() << endl;
		cout << "Fraction minus Int test completed successfully" << endl;
	}
	else {
		cout << " != " << c.getText() << endl;
		cout << "Fraction minus Int test completed failed" << endl;
	}
	cout << endl;

	c = "157/7";
	cout << num << " - " << a.getText();
	if (testIntMinusFraction(a, num, c)) {
		cout << " = " << c.getText() << endl;
		cout << "Int minus Fraction test completed successfully" << endl;
	}
	else {
		cout << " != " << c.getText() << endl;
		cout << "Int minus Fraction test completed failed" << endl;
	}
	cout << endl;

	if (testFloatOperator(a)) {
		cout << "a = " << a.getText() << endl;
		cout << "(float)a = " << (float)a << endl;
		cout << "Float operator test completed successfully" << endl;
	}
	else {
		cout << "a != " << a.getText() << endl;
		cout << "(float)a != " << (float)a << endl;
		cout << "Float operator test completed failed" << endl;
	}
	cout << endl;
	return 0;
}