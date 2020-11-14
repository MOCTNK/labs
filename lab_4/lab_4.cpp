#include <iostream>
#include "Fraction.h";
#include "Mixed.h";
#include "Result.h";
using namespace std;

bool testFractionToMixed(Fraction a, Mixed b) {
	Mixed c(a);
	if (b.getWhole() == c.getWhole() and b.getNumerator() == c.getNumerator() and b.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testMixedToResult(Mixed a, Result b) {
	Result c(a);
	if (b.getNumerator() == c.getNumerator() and b.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testMixedToMixed(Mixed &a, Mixed b) {
	Mixed c(b);
	a = c;
	if (b.getWhole() == c.getWhole() and b.getNumerator() == c.getNumerator() and b.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testResultToResult(Result &a, Result b) {
	Result c(b);
	a = c;
	if (b.getNumerator() == c.getNumerator() and b.getDenominator() == c.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}


int main()
{
	Fraction a(23, 7);
	Mixed b(3, 2, 7);

	if (testFractionToMixed(a, b)) {
		cout << a.getText() << " = " << b.getText() << endl;
		cout << "Constructor Fraction to Mixed test completed successfully" << endl;
	}
	else {
		cout << a.getText() << " != " << b.getText() << endl;
		cout << "Constructor Fraction to Mixed test completed failed" << endl;
	}

	cout << endl; 

	Mixed c(3,2,3);
	Result d(11, 3);
	if (testMixedToResult(c, d)) {
		cout << c.getText() << " = " << d.getText() << endl;
		cout << "Constructor Mixed to Result test completed successfully" << endl;
	}
	else {
		cout << c.getText() << " != " << d.getText() << endl;
		cout << "Constructor Mixed to Result test completed failed" << endl;
	}

	cout << endl;

	Mixed e(3, 23, 25);
	Mixed x;
	if (testMixedToMixed(x, e)) {
		cout << e.getText() << " = " << x.getText() << endl;
		cout << "Constructor Mixed to Mixed test completed successfully" << endl;
	}
	else {
		cout << c.getText() << " != " << d.getText() << endl;
		cout << "Constructor Mixed to Mixed test completed failed" << endl;
	}

	cout << endl;

	Result f(40, 13);
	Result z;
	if (testResultToResult(z, f)) {
		cout << f.getText() << " = " << z.getText() << endl;
		cout << "Constructor Result to Result test completed successfully" << endl;
	}
	else {
		cout << c.getText() << " != " << d.getText() << endl;
		cout << "Constructor Result to Result test completed failed" << endl;
	}
	return 0;
}