#include "classes.h";

Fraction::Fraction() {
	error = false;
	set(1, 1);
}

Fraction::Fraction(int get_numerator, int get_denominator) {
	error = false;
	set(get_numerator, get_denominator);
}

int Fraction::count = 0;

void Fraction::set(int get_numerator, int get_denominator) {
	if (get_numerator == 0 || get_denominator == 0) {
		error = true;
	}
	if (error == false) {
		count++;
		if (get_denominator < 0) {
			get_numerator *= -1;
			get_denominator *= -1;
		}
		numerator = get_numerator;
		denominator = get_denominator;
		reduction();

		char *str1 = new char[1];
		str1[0] = '\0';
		toString(numerator, str1);

		if (denominator != 1) {
			char *str2 = new char[1];
			str2[0] = '\0';
			toString(denominator, str2);

			char str3[2] = "/";

			concatenation(str1, str3);
			concatenation(str1, str2);
		}

		text = str1;
	}
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