#include <iostream>
#include "Fraction.h"
#include "testFraction.h"
using namespace std;


int main()
{
	if (testSet(21474836470000008, 2147483647)) {
		cout << "Set test completed successfully" << endl;
	}
	else {
		cout << "Set test completed failed" << endl;
	}

	cout << endl;

	if (testSet(2147, 0)) {
		cout << "Set test completed successfully" << endl;
	}
	else {
		cout << "Set test completed failed" << endl;
	}

	cout << endl;

	if (testSet(1, 2)) {
		cout << "Set test completed successfully" << endl;
	}
	else {
		cout << "Set test completed failed" << endl;
	}

	cout << endl;

	Fraction a;
	if (testAdd(a)) {
		cout << "Addition test completed successfully" << endl;
	}
	else {
		cout << "Addition test completed failed" << endl;
	}

	cout << endl;

	if (testDivide(a)) {
		cout << "Division test completed successfully" << endl;
	}
	else {
		cout << "Division test completed failed" << endl;
	}

	cout << endl;

	if (testSubtract(a)) {
		cout << "Subtraction test completed successfully" << endl;
	}
	else {
		cout << "Subtraction test completed failed" << endl;
	}

	cout << endl;

	if (testMultiply(a)) {
		cout << "Multiplication test completed successfully" << endl;
	}
	else {
		cout << "Multiplication test completed failed" << endl;
	}

	cout << endl;

	a.set(1, 2);
	if (testAdd(a)) {
		cout << "Addition test completed successfully" << endl;
	}
	else {
		cout << "Addition test completed failed" << endl;
	}

	cout << endl;

	if (testDivide(a)) {
		cout << "Division test completed successfully" << endl;
	}
	else {
		cout << "Division test completed failed" << endl;
	}

	cout << endl;

	if (testSubtract(a)) {
		cout << "Subtraction test completed successfully" << endl;
	}
	else {
		cout << "Subtraction test completed failed" << endl;
	}

	cout << endl;

	if (testMultiply(a)) {
		cout << "Multiplication test completed successfully" << endl;
	}
	else {
		cout << "Multiplication test completed failed" << endl;
	}
	return 0;
}

