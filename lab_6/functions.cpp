#include "functions.h";

char* toString(int number) {
	if (number == 0) {
		char *str = new char[2];
		str[0] = '0';
		str[1] = '\0';
		return str;
	}
	else {
		int size = 0;
		int sign = 0;
		char minus[2] = "-";
		char *str = new char[1];
		if (number < 0) {
			sign = 1;
			number *= -1;
		}
		for (int i = 0;; i++) {
			if (number == 0) {
				break;
			}
			else {
				increaseSize(str);
				str[i] = (number % 10) + '0';
				str[i + 1] = '\0';
				number /= 10;
				size++;
			}
		}

		if (sign == 1) {
			concatenation(str, minus);
			size++;
		}

		for (int i = 0; i < size / 2; i++) {
			int t = str[i];
			str[i] = str[size - 1 - i];
			str[size - 1 - i] = t;
		}

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

void concatenation(char *&str1, char *str2) {
	for (int i = strlen(str1), j = 0;; i++, j++) {
		if (str2[j] == '\0') {
			break;
		}
		increaseSize(str1);
		str1[i] = str2[j];
		str1[i + 1] = '\0';
	}
}