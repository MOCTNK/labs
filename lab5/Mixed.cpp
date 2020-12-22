#include "Mixed.h";
#include "functions.h";

Mixed::Mixed() {
	set(0, 1, 1);
};

Mixed::Mixed(int wh, int numerator, int denominator) {
	set(wh, numerator, denominator);
};

Mixed::Mixed(Mixed &a) {
	set(a.getWhole(), a.getNumerator(), a.getDenominator());
};

Mixed::Mixed(Fraction &a) {
	set(0, a.getNumerator(), a.getDenominator());
};

Mixed &Mixed::operator = (const char* str) {
	char* w = new char[1];
	char* num = new char[1];
	char* den = new char[1];
	int k = 0;
	for (int i = 1, j = 0; i < strlen(str); i++, j++) {
		if (str[i] == ')') {
			j = -1;
			k = 1;
			continue;
		}
		if (str[i] == '/') {
			j = -1;
			k = 2;
			continue;
		}
		if (k == 0) {
			increaseSize(w);
			w[j] = str[i];
			w[j + 1] = '\0';
		}
		if (k == 1) {
			increaseSize(num);
			num[j] = str[i];
			num[j + 1] = '\0';
		}
		if (k == 2) {
			increaseSize(den);
			den[j] = str[i];
			den[j + 1] = '\0';
		}
	}
	set(atoi(w), atoi(num), atoi(den));
	return *this;
}

Mixed Mixed::operator + (Mixed b) {
	Mixed c(this->getWhole(), this->getNumerator(), this->getDenominator());
	c.add(b);
	return c;
}

Mixed Mixed::operator - (Mixed b) {
	Mixed c(this->getWhole(), this->getNumerator(), this->getDenominator());
	c.subtract(b);
	return c;
}

Mixed operator + (Mixed a, int num) {
	Mixed b(num, 0, 1);
	a.add(b);
	return a;
}

Mixed operator + (int num, Mixed a) {
	Mixed b(num, 0, 1);
	b.add(a);
	return b;
}

Mixed operator - (Mixed a, int num) {
	Mixed b(num, 0, 1);
	a.subtract(b);
	return a;
}

Mixed operator - (int num, Mixed a) {
	Mixed b(num, 0, 1);
	b.subtract(a);
	return b;
}

std::ofstream &operator << (std::ofstream &fout, Mixed a) {
	fout << a.getText();
	return fout;
}

std::ifstream &operator >> (std::ifstream &fin, Mixed &a) {
	char* str = new char;
	fin >> str;
	a = str;
	return fin;
}

std::ostream &operator << (std::ostream &out, Mixed a) {
	out << a.getText();
	return out;
}

std::istream &operator >> (std::istream &in, Mixed &a) {
	char* str = new char;
	in >> str;
	a = str;
	return in;
}

void Mixed::read(std::ifstream &fin) {
	char* str;
	fin.read((char *)&str, sizeof(str));
	char* w = new char[1];
	char* num = new char[1];
	char* den = new char[1];
	int k = 0;
	for (int i = 1, j = 0; i < strlen(str); i++, j++) {
		if (str[i] == ')') {
			j = -1;
			k = 1;
			continue;
		}
		if (str[i] == '/') {
			j = -1;
			k = 2;
			continue;
		}
		if (k == 0) {
			increaseSize(w);
			w[j] = str[i];
			w[j + 1] = '\0';
		}
		if (k == 1) {
			increaseSize(num);
			num[j] = str[i];
			num[j + 1] = '\0';
		}
		if (k == 2) {
			increaseSize(den);
			den[j] = str[i];
			den[j + 1] = '\0';
		}
	}
	set(atoi(w), atoi(num), atoi(den));
}

void Mixed::set(int wh, int numerator, int denominator) {
	int num = 0;
	int sign = 1;
	if (numerator < 0) {
		numerator *= -1;
		sign = -1;
	}
	if (denominator < 0) {
		denominator *= -1;
		sign = -1;
	}

	if (numerator > denominator) {
		num = numerator / denominator;
		numerator = numerator - denominator * num;
	}

	if (wh == 0 and num == 0 and sign == -1) {
		numerator *= -1;
	}
	whole = sign * (wh + num);
	Fraction::set(numerator, denominator);
}

void Mixed::add(Mixed b) {
	Fraction num1;
	Fraction num2;
	num1 = toFraction();
	num2 = b.toFraction();
	set(0, (num1.getNumerator() * num2.getDenominator()) + (num1.getDenominator() * num2.getNumerator()),
		num1.getDenominator() * num2.getDenominator());
}

void Mixed::subtract(Mixed b) {
	Fraction num1;
	Fraction num2;
	num1 = toFraction();
	num2 = b.toFraction();
	set(0, (num1.getNumerator() * num2.getDenominator()) - (num1.getDenominator() * num2.getNumerator()),
		num1.getDenominator() * num2.getDenominator());
}

void Mixed::multiply(Mixed b) {
	Fraction num1;
	Fraction num2;
	num1 = toFraction();
	num2 = b.toFraction();
	set(0, num1.getNumerator() * num2.getNumerator(), num1.getDenominator() * num2.getDenominator());
}

void Mixed::divide(Mixed b) {
	Fraction num1;
	Fraction num2;
	num1 = toFraction();
	num2 = b.toFraction();
	set(0, num1.getNumerator() * num2.getDenominator(), num1.getDenominator() * num2.getNumerator());
}

char* Mixed::getText() {
	char *str1 = new char[2];
	str1[0] = '(';
	str1[1] = '\0';
	char *str2 = toString(whole);
	char str3[2] = ")";
	char *str4 = Fraction::getText();
	concatenation(str1, str2);
	concatenation(str1, str3);
	concatenation(str1, str4);
	return str1;
}

char* Mixed::toFraction() {
	Fraction b;
	int sign = 1;
	if (whole < 0) {
		whole *= -1;
		sign = -1;
	}
	b.set(sign * (whole * getDenominator() + getNumerator()), getDenominator());
	return b.getText();
}
