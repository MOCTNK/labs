#include "Deque.h";

void Deque::getDeque() {
	cout << "Deque: ";
	if (count != 0) {
		Element *e = front;
		for (int i = 0; i < count; i++) {
			cout << e->obj->getText() << " ";
			e = e->next;
		}
		cout << endl;
	}
	else {
		cout << "empty!" << endl;
	}
}

void Deque::pushFront(Fraction *a) {
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

void Deque::pushBack(Fraction *a) {
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

void Deque::popFront() {
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

void Deque::clear() {
	int size = count;
	for (int i = 0; i < size; i++) {
		popFront();
	}
}

Deque::~Deque() {
	cout << "delete Deque" << endl;
	clear();
}