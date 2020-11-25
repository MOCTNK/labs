#include  "testFraction.h"

bool testSet(int n, int d) {
	try {
		Fraction a(n, d);
		cout << "Object is set" << endl;
		return true;
	}
	catch (exception &ex) {
		cout << ex.what() << endl;
		return false;
	}
}

bool testAdd(Fraction b) {
	try {
		Fraction a(2, 3);
		a.add(b);
		cout << "Fractions are added" << endl;
		return true;
	}
	catch (exception &ex) {
		cout << ex.what() << endl;
		return false;
	}
}

bool testDivide(Fraction b) {
	try {
		Fraction a(2, 3);
		a.divide(b);
		cout << "Fractions are added" << endl;
		return true;
	}
	catch (exception &ex) {
		cout << ex.what() << endl;
		return false;
	}
}

bool testSubtract(Fraction b) {
	try {
		Fraction a(2, 3);
		a.subtract(b);
		cout << "Fractions are added" << endl;
		return true;
	}
	catch (exception &ex) {
		cout << ex.what() << endl;
		return false;
	}
}

bool testMultiply(Fraction b) {
	try {
		Fraction a(2, 3);
		a.multiply(b);
		cout << "Fractions are added" << endl;
		return true;
	}
	catch (exception &ex) {
		cout << ex.what() << endl;
		return false;
	}
}