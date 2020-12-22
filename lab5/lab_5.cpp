#include <iostream>
#include "Fraction.h";
#include "Mixed.h";
#include "Result.h";
#include "Deque.h";
using namespace std;

bool testPushFrontFraction(Deque &A, Fraction &a) {
	A.pushFront(&a);
	if (A.getFront()->getNumerator() == a.getNumerator() and A.getFront()->getDenominator() == a.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testPushFrontMixed(Deque &A, Mixed &a) {
	A.pushFront(&a);
	if (A.getFront()->getNumerator() == a.getNumerator() and A.getFront()->getDenominator() == a.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testPushBackMixed(Deque &A, Mixed &a) {
	A.pushBack(&a);
	if (A.getBack()->getNumerator() == a.getNumerator() and A.getBack()->getDenominator() == a.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testPushBackFraction(Deque &A, Fraction &a) {
	A.pushBack(&a);
	if (A.getBack()->getNumerator() == a.getNumerator() and A.getBack()->getDenominator() == a.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testPopFront(Deque &A) {
	Fraction *f = A.getFront();
	A.popFront();
	if (A.getFront()->getNumerator() != f->getNumerator() or A.getFront()->getDenominator() != f->getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool testClearDeque(Deque &A) {
	A.clear();
	if (A.count == 0) {
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
	Deque A;
	if (testPushFrontFraction(A,a)) {
		cout << "Push front Fraction test completed successfully" << endl;
	}
	else {
		cout << "Push front Fraction test completed failed" << endl;
	}

	A.getDeque();
	cout << endl;

	if (testPushFrontMixed(A, b)) {
		cout << "Push front Mixed test completed successfully" << endl;
	}
	else {
		cout << "Push front Mixed test completed failed" << endl;
	}

	A.getDeque();
	cout << endl;
	Fraction c(66, 105);
	Mixed d(9, 5, 2);

	if (testPushBackMixed(A, d)) {
		cout << "Push back Mixed test completed successfully" << endl;
	}
	else {
		cout << "Push back Mixed test completed failed" << endl;
	}

	A.getDeque();
	cout << endl;

	if (testPushBackFraction(A, c)) {
		cout << "Push back Fraction test completed successfully" << endl;
	}
	else {
		cout << "Push back Fraction test completed failed" << endl;
	}

	A.getDeque();
	cout << endl;

	if (testPopFront(A)) {
		cout << "Pop front test completed successfully" << endl;
	}
	else {
		cout << "Pop front test completed failed" << endl;
	}

	A.getDeque();
	cout << endl;

	if (testClearDeque(A)) {
		cout << "Clear deque test completed successfully" << endl;
	}
	else {
		cout << "Clear deque test completed failed" << endl;
	}

	A.getDeque();
	cout << endl;
	return 0;
}