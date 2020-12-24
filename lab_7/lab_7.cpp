#include <iostream>
#include "Fraction.h";
#include "Deque.h";
#include "test.h";
using namespace std;

int main()
{
	Deque <Fraction> dequeFraction;
	Fraction a(6,3);
	cout << "Tests for Fraction" << endl;
	cout << endl;
	if (testPushFront(dequeFraction, a)) {
		cout << "Push front Fraction test completed successfully" << endl;
	}
	else {
		cout << "Push front Fraction test completed failed" << endl;
	}

	dequeFraction.printDeque();
	cout << endl;

	Fraction b(7, 11);

	if (testPushBack(dequeFraction, b)) {
		cout << "Push back Fraction test completed successfully" << endl;
	}
	else {
		cout << "Push back Fraction test completed failed" << endl;
	}

	dequeFraction.printDeque();

	cout << endl;


	if (testPopFront(dequeFraction)) {
		cout << "Pop front Fraction test completed successfully" << endl;
	}
	else {
		cout << "Pop front Fraction test completed failed" << endl;
	}

	dequeFraction.printDeque();
	cout << endl;

	Deque <int> dequeInt;
	cout << "Tests for Int" << endl;
	cout << endl;
	if (testPushFront(dequeInt, 63)) {
		cout << "Push front Int test completed successfully" << endl;
	}
	else {
		cout << "Push front Int test completed failed" << endl;
	}

	dequeInt.printDeque();
	cout << endl;


	if (testPushBack(dequeInt, 108)) {
		cout << "Push back Int test completed successfully" << endl;
	}
	else {
		cout << "Push back Int test completed failed" << endl;
	}

	dequeInt.printDeque();

	cout << endl;


	if (testPopFront(dequeInt)) {
		cout << "Pop front Int test completed successfully" << endl;
	}
	else {
		cout << "Pop front Int test completed failed" << endl;
	}

	dequeInt.printDeque();
	cout << endl;

	Deque <float> dequeFloat;
	cout << "Tests for Float" << endl;
	cout << endl;
	if (testPushFront(dequeFloat, 56.367f)) {
		cout << "Push front Float test completed successfully" << endl;
	}
	else {
		cout << "Push front Float test completed failed" << endl;
	}

	dequeFloat.printDeque();
	cout << endl;


	if (testPushBack(dequeFloat, 352.78f)) {
		cout << "Push back Float test completed successfully" << endl;
	}
	else {
		cout << "Push back Float test completed failed" << endl;
	}

	dequeFloat.printDeque();

	cout << endl;


	if (testPopFront(dequeFloat)) {
		cout << "Pop front Float test completed successfully" << endl;
	}
	else {
		cout << "Pop front Float test completed failed" << endl;
	}

	dequeFloat.printDeque();
	return 0;
}