#include "classes.h";
#include <iostream>;

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
		}
		reduction();

		char *str1 = toString(numerator);
		char *str2 = toString(denominator);
		char str3[2] = "/";
		concatenation(str1, str3);
		concatenation(str1, str2);

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

Fraction &Fraction::operator = (const char* str) {
	char* num = new char[1];
	char* den = new char[1];
	int k = 0;
	for (int i = 0, j = 0; i < strlen(str); i++, j++) {
		if (str[i] == '/') {
			j = -1;
			k = 1;
			continue;
		}
		if (k == 0) {
			increaseSize(num);
			num[j] = str[i];
			num[j + 1] = '\0';
		}
		else {
			increaseSize(den);
			den[j] = str[i];
			den[j + 1] = '\0';
		}
	}
	set(atoi(num), atoi(den));
	return *this;
}

Fraction Fraction::operator + (Fraction b) {
	Fraction c(this->getNumerator(), this->getDenominator());
	c.add(b);
	return c;
}

Fraction Fraction::operator - (Fraction b) {
	Fraction c(this->getNumerator(), this->getDenominator());
	c.subtract(b);
	return c;
}

Fraction operator + (Fraction a, int num) {
	Fraction b(num, 1);
	a.add(b);
	return a;
}

Fraction operator + (int num, Fraction a) {
	Fraction b(num, 1);
	b.add(a);
	return b;
}

Fraction operator - (Fraction a, int num) {
	Fraction b(num, 1);
	a.subtract(b);
	return a;
}

Fraction operator - (int num, Fraction a) {
	Fraction b(num, 1);
	b.subtract(a);
	return b;
}

Fraction::operator float() {
	float a = (float)numerator / (float)denominator;
	return a;
}

std::ofstream &operator << (std::ofstream &fout, Fraction a) {
	fout << a.getText();
	return fout;
}

std::ifstream &operator >> (std::ifstream &fin, Fraction &a) {
	char* str = new char;
	fin >> str;
	a = str;
	return fin;
}

std::ostream &operator << (std::ostream &out, Fraction a) {
	out << a.getText();
	return out;
}

std::istream &operator >> (std::istream &in, Fraction &a) {
	char* str = new char;
	in >> str;
	a = str;
	return in;
}

void Fraction::write(std::ofstream &fout) {
	 fout.write((char *)&text, sizeof(text));
}

void Fraction::read(std::ifstream &fin) {
	char* str;
	fin.read((char *)&str, sizeof(str));
	char* num = new char[1];
	char* den = new char[1];
	disassemble(str, num, den);
	set(atoi(num), atoi(den));
}

void Fraction::increaseSize(char *&str) {
	int size = strlen(str) + 1;
	char *newStr = new char[size + 1];
	for (int i = 0; i < size; i++) {
		newStr[i] = str[i];
	}
	delete[] str;
	str = newStr;
}