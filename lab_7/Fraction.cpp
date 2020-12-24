#include "Fraction.h";
#include < string.h >
using namespace std;

Fraction::Fraction() {
	set(1, 1);
}

Fraction::Fraction(int get_numerator, int get_denominator) {
	set(get_numerator, get_denominator);
}

int Fraction::count = 0;

void Fraction::set(int get_numerator, int get_denominator) {
	if (get_denominator != 0) {
		count++;
		if (get_denominator < 0) {
			get_numerator *= -1;
			get_denominator *= -1;
		}
		numerator = get_numerator;
		if (get_numerator == 0) {
			denominator = 1;
		}
		else {
			denominator = get_denominator;
			reduction();
		}

		char *str1 = toString(numerator);
		char *str2 = toString(denominator);
		char *str3 = new char[2];
		str3[0] = '/';
		str3[1] = '\0';
		concatenation(str1, str3);
		concatenation(str1, str2);

		text = new char[strlen(str1)];
		strcpy(text, str1);
		increaseSize(text, strlen(str1));
		text[strlen(str1)] = '\0';
	}
}

bool operator == (Fraction &a, Fraction &b) {
	if (a.getNumerator() == b.getNumerator() and a.getDenominator() == b.getDenominator()) {
		return true;
	}
	else {
		return false;
	}
}

std::ostream &operator << (std::ostream &out, Fraction a) {
	out << a.getText();
	return out;
}

void Fraction::add(Fraction b) {
	set((numerator * b.denominator) + (denominator * b.numerator), denominator * b.denominator);
}

void Fraction::subtract(Fraction b) {
	set((numerator * b.denominator) - (denominator * b.numerator), denominator * b.denominator);
}

void Fraction::multiply(Fraction b) {
	set(numerator * b.numerator, denominator * b.denominator);
}

void Fraction::divide(Fraction b) {
	set(numerator * b.denominator, denominator * b.numerator);
}

void Fraction::reduction() {
	int k = 0;
	for (;;) {
		if ((numerator == 1 && denominator == 1) || k == 1) {
			break;
		}
		for (int i = 2;; i++) {
			if (numerator % i == 0 && denominator % i == 0) {
				numerator /= i;
				denominator /= i;
				break;
			}
			if (numerator == i || denominator == i) {
				k = 1;
				break;
			}
		}
	}
}

Fraction &Fraction::operator = (Fraction &a) {
	this->set(a.numerator, a.denominator);
	return *this;
}