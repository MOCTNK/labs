#include <iostream>
#include "Fraction.h";
#include "Mixed.h";
#include "Result.h";
#include "Deque.h";
#include "test.h";
using namespace std;

int main()
{
	Fraction a(23, 7);
	Mixed b(3, 2, 7);
	Deque A;
	if (testPushFrontFraction(A,a)) {
		cout << "Push front Fraction test completed successfully" << endl;
	}
	else {
		cout << "Push front Fraction test completed failed" << endl;
	}

	A.printDeque();
	cout << endl;

	if (testPushFrontMixed(A, b)) {
		cout << "Push front Mixed test completed successfully" << endl;
	}
	else {
		cout << "Push front Mixed test completed failed" << endl;
	}

	A.printDeque();
	cout << endl;
	Fraction c(66, 105);
	Mixed d(9, 5, 2);

	if (testPushBackMixed(A, d)) {
		cout << "Push back Mixed test completed successfully" << endl;
	}
	else {
		cout << "Push back Mixed test completed failed" << endl;
	}

	A.printDeque();
	cout << endl;

	if (testPushBackFraction(A, c)) {
		cout << "Push back Fraction test completed successfully" << endl;
	}
	else {
		cout << "Push back Fraction test completed failed" << endl;
	}

	A.printDeque();
	cout << endl;

	if (testPopFront(A)) {
		cout << "Pop front test completed successfully" << endl;
	}
	else {
		cout << "Pop front test completed failed" << endl;
	}

	A.printDeque();
	cout << endl;

	if (testClearDeque(A)) {
		cout << "Clear deque test completed successfully" << endl;
	}
	else {
		cout << "Clear deque test completed failed" << endl;
	}

	A.printDeque();
	cout << endl;
	return 0;
}