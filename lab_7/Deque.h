#pragma once
#include <iostream>;
#include "Fraction.h";
using namespace std;

template <class T> class Deque {
	class Element {
	public:
		Element *next = NULL;
		T obj;
	};
public:
	void printDeque();
	void pushFront(T a);
	void pushBack(T a);
	void popFront();
	void clear();
	Element *getFront() { return front; };
	Element *getBack() { return back; };
private:
	Element *front = NULL;
	Element *back = NULL;
	int count = 0;
};

template <class T> void Deque<T>::printDeque() {
	cout << "Deque: ";
	if (count != 0) {
		Element *e = front;
		for (int i = 0; i < count; i++) {
			cout << e->obj << " ";
			e = e->next;
		}
		cout << endl;
	}
	else {
		cout << "empty!" << endl;
	}
}

template <class T> void Deque<T>::pushFront(T a) {
	if (count == 0) {
		front = new Element;
		back = front;
	}
	else {
		Element *e = front;
		front = new Element;
		front->next = e;
	}

	front->obj = a;
	count++;
}

template <class T> void Deque<T>::pushBack(T a) {
	if (count == 0) {
		back = new Element;
		front = back;
	}
	else {
		Element *e = back;
		back = new Element;
		e->next = back;
	}
	back->obj = a;
	count++;
}

template <class T> void Deque<T>::popFront() {
	if (count != 0) {
		Element *e = front;
		if (count == 1) {
			front = NULL;
			back = NULL;
		}
		else {
			front = front->next;
		}
		delete e;
		count--;
	}
	else {
		cout << "Error! Deque is empty!" << endl;
	}
}

template <class T> void Deque<T>::clear() {
	int size = count;
	for (int i = 0; i < size; i++) {
		popFront();
	}
}