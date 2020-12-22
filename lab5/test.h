#pragma once
#include <iostream>
#include "Fraction.h";
#include "Mixed.h";
#include "Result.h";
#include "Deque.h";
using namespace std;

bool testPushFrontFraction(Deque &A, Fraction &a);
bool testPushFrontMixed(Deque &A, Mixed &a);
bool testPushBackMixed(Deque &A, Mixed &a);
bool testPushBackFraction(Deque &A, Fraction &a);
bool testPopFront(Deque &A);
bool testClearDeque(Deque &A);