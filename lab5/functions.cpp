#include "functions.h";

char* toString(int number) {

	if (number == 0) {
		char *str = new char[2];
		str[0] = '0';
		str[1] = '\0';
		return str;
	}
	else {
		int size = getSizeInt(number);
		int sign = 0;
		char minus[2] = "-";
		char *str = new char[size];
		if (number < 0) {
			sign = 1;
			number *= -1;
		}
		for (int i = 0;; i++) {
			if (number == 0) {
				break;
			}
			else {
				str[i] = (number % 10) + '0';
				number /= 10;
			}
		}

		if (sign == 1) {
			concatenation(str, minus);
		}

		for (int i = 0; i < size / 2; i++) {
			int t = str[i];
			str[i] = str[size - 1 - i];
			str[size - 1 - i] = t;
		}

		increaseSize(str);
		str[size] = '\0';
		return str;
	}
}

void increaseSize(char *&str) {
	int size = strlen(str) + 1;
	char *newStr = new char[size + 1];
	for (int i = 0; i < size; i++) {
		newStr[i] = str[i];
	}
	delete[] str;
	str = newStr;
}

int random(const int min, const int max) {
	return rand() % (max - min + 1) + min;
}


void concatenation(char *&str1, char *str2) {
	int size = strlen(str1) + strlen(str2);
	char *newStr = new char[size];
	int i = 0;
	for (; i < strlen(str1); i++) {
		newStr[i] = str1[i];
	}
	for (int j = 0; j < strlen(str2); j++, i++) {
		newStr[i] = str2[j];
	}
	increaseSize(newStr);
	newStr[size] = '\0';
	delete[] str1;
	str1 = newStr;
}

void disassemble(char *str, char *str1, char *str2) {
	int k = 0;
	for (int i = 0, j = 0; i < strlen(str); i++, j++) {
		if (str[i] == '/') {
			j = -1;
			k = 1;
			continue;
		}
		if (k == 0) {
			increaseSize(str1);
			str1[j] = str[i];
			str1[j + 1] = '\0';
		}
		else {
			increaseSize(str2);
			str2[j] = str[i];
			str2[j + 1] = '\0';
		}
	}
}

void strcpy(char *a, char *b) {
	for (int i = 0; i < strlen(b); i++) {
		a[i] = b[i];
	}
}

int getSizeInt(int number) {
	int result = 0;

	while (number != 0) {
		number /= 10;
		result++;
	}

	return result;
}