#pragma once
#include <iostream>
#include "Fraction.h";
#include "Deque.h";
using namespace std;

template <class T> bool testPushFront(Deque<T> &A, T a) {
	A.pushFront(a);
	if (A.getFront()->obj == a) {
		return true;
	}
	else {
		return false;
	}
};

template <class T> bool testPushBack(Deque<T> &A, T a) {
	A.pushBack(a);
	if (A.getBack()->obj == a) {
		return true;
	}
	else {
		return false;
	}
};

template <class T> bool testPopFront(Deque<T> &A) {
	T b = A.getFront()->obj;
	A.popFront();
	if (A.getFront()->obj == b) {
		return false;
	}
	else {
		return true;
	}
};