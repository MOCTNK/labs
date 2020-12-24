#include "test.h";

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