#pragma once
#include <iostream>;
#include "Fraction.h";
#include "Mixed.h";
#include "Result.h";
using namespace std;

class Deque {
	class Element {
	public:
		Element *next = NULL;
		Fraction *obj;
	};
public:
	Element *front = NULL;
	Element *back = NULL;
	int count = 0;

	void getDeque();
	void pushFront(Fraction *a);
	void pushBack(Fraction *a);
	void popFront();
	void clear();
	Fraction *getFront() { return front->obj; };
	Fraction *getBack() { return back->obj; };
	~Deque();
};