#include <iostream>;
#include <fstream>;
#include "classes.h";
#include "time.h";
using namespace std;

bool testFileTXT(Fraction *a, Fraction *b) {
	cout << "Text file:" << endl;
	cout << "Added to file" << endl;
	ofstream fout("data.txt", ios::app);
	if (!fout) {
		return false;
	}
	else {
		for (int i = 0; i < 5; i++) {
			cout << a[i].getText() << endl;
			fout << a[i];
			if (i < 4) {
				fout << '\n';
			}
		}
	}
	fout.close();
	cout << endl;

	cout << "Loaded from file" << endl;
	ifstream fin("data.txt");
	if (!fin) {
		return false;
	}
	else {
		int i = 1;
		char ch;
		fin >> b[0];
		cout << b[0].getText() << endl;
		while (fin.get(ch)) {
			if (ch == '\n') {
				fin >> b[i];
				cout << b[i].getText() << endl;
				i++;
			}
		}
	}
	fin.close();

	bool error = false;
	for (int j = 0; j < 5; j++) {
		if ((float)a[j] != (float)b[j]) {
			bool error = true;
		}
	}
	cout << endl;

	if (error == true) {
		return false;
	}
	else {
		return true;
	}
}

bool testFileDAT(Fraction *a, Fraction *b) {
	cout << "Binary file:" << endl;
	cout << "Added to file" << endl;

	ofstream fout("data.dat", ios::binary);
	char **aNum = new char*[5];
	if (!fout) {
		return false;
	}
	else {
		for (int i = 0; i < 5; i++) {
			aNum[i] = a[i].getText();
			cout << aNum[i] << endl;
			fout.write((char *)&aNum[i], sizeof(aNum[i]));
		}
	}
	fout.close();
	cout << endl;

	cout << "Loaded from file" << endl;
	ifstream fin("data.dat");
	char **bNum = new char*[5];
	if (!fin) {
		return false;
	}
	else {
		for (int i = 0; i < 5; i++) {
			fin.read((char *)&bNum[i], sizeof(bNum[i]));
			cout << bNum[i] << endl;
			b[i] = bNum[i];
		}
	}
	fin.close();

	bool error = false;
	for (int j = 0; j < 5; j++) {
		if ((float)a[j] != (float)b[j]) {
			bool error = true;
		}
	}

	delete[] aNum;
	delete[] bNum;
	cout << endl;

	if (error == true) {
		return false;
	}
	else {
		return true;
	}
}

int main()
{
	srand(time(NULL));
	ofstream fout("data.txt");
	fout << "";
	fout.close();
	ofstream fout2("data.dat");
	fout2 << "";
	fout2.close();
	Fraction *a = new Fraction[5];
	Fraction *b = new Fraction[5];
	
	for (int i = 0; i < 5; i++) {
		a[i].set(random(2,100), random(2, 100));
	}

	if (testFileTXT(a, b)) {
		cout << "Adding and loading objects from a text file test completed successfully" << endl;
	}
	else {
		cout << "Adding and loading objects from a text file test completed failed" << endl;
	}

	cout << endl;

	if (testFileDAT(a, b)) {
		cout << "Adding and loading objects from a binary file test completed successfully" << endl;
	}
	else {
		cout << "Adding and loading objects from a binary file test completed failed" << endl;
	}

	delete[] a;
	delete[] b;
	return 0;
}
