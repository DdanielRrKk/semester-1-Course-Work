#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

const int N = 25;
const char NAME[] = "my.dat";

struct patuvania {
	char korab[20];
	char kapitan[20];
	double cena1;
	double cena2;
	int pasaj1;
	int pasaj2;
};

void syzdai(struct patuvania pat[], int &k);
void izvejdane_prevoz(struct patuvania pat[], int &k);
void izvejdane_put(struct patuvania pat[], int &k);
void menu();

int main(void) {
	menu();
	return 0;
}

void menu() {
	int n;
	struct patuvania pat[N];
	int izbor;
	do {
		do {
			cout << endl << "--------MENU---------" << endl;
			cout << "1. Syzdaite fail" << endl;
			cout << "2. Izvejdane na dannite za prevozite na korab, po ime na korab" << endl;
			cout << "3. Izvejdane na dannite za morskoto pytuvane s nai-golqma obshta suma na prodadenite bileti" << endl;
			cout << "4. Krai" << endl;
			cout << "Vyvedete svoq izbor ot 1 do 4: " << endl;
			cin >> izbor;
		} while (izbor < 1 || izbor>4);
		switch (izbor) {
		case 1: syzdai(pat, n);
		case 2: izvejdane_prevoz(pat, n);
		case 3: izvejdane_put(pat, n);
		default: cout << "**********krai**********";
		}
	} while (izbor != 4);
}

void syzdai(struct patuvania pat[], int &k) {
	system("cls");
	fstream fp;
	int n;
	cout << "Vyvedete broq na pytuvaniqta" << endl;
	do {
		cin >> n;
	} while (n < 1 || n>25);
	fp.open (NAME, ios::binary, ios::in);
	if (fp.fail()) {
		cout << "greshka pri syzdavane na faila" << endl;
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		fp.ignore();
		cout << "Vyvedete danni za pytuvane nomer " << i + 1 << endl;
		cout << "Ime na koryba" << endl;
		cin.getline(pat[i].korab, 20);
		cout << "Ime na kapitana" << endl;
		cin.getline(pat[i].kapitan, 20);
		cout << "Cena za pyrva klasa" << endl;
		cin >> pat[i].cena1;
		cout << "Cena za vtor klasa" << endl;
		cin >> pat[i].cena2;
		cout << "Broi pasajeri v pyrva klasa" << endl;
		cin >> pat[i].pasaj1;
		cout << "Broi pasajeri vyv vtora klasa" << endl;
		cin >> pat[i].pasaj2;
	}
	fp.write((char*)&pat, n * sizeof(patuvania));
	fp.close();
}

void izvejdane_prevoz(struct patuvania pat[], int &k) {
	system("cls");
	fstream fp;
	int n;
	int i;
	string tyrsach;
	cout << "Vyvedete imeto na koryba: " << endl;
	getline(cin, tyrsach);
	fp.open(NAME, ios::binary, ios::in);
	if (fp.fail()) {
		cout << "Greshka pri otvarqneto na faila" << endl;
		exit(1);
	}
	fp.read((char*) &pat, sizeof(patuvania));
	for (i = 0; i < n; i++) {
		if (pat[i].korab == tyrsach) {
			break;
		}
	}
	cout << "Dannite za prevozite na korab " << pat[i].korab << ":" << endl;
	cout << "Kapitan: " << pat[i].kapitan << endl;
	cout << "Cena za pyrva klasa: " << pat[1].cena1 << endl;
	cout << "Cena za vtora klasa: " << pat[i].cena2 << endl;
	cout << "Pasajeri v pyrva lasa: " << pat[i].pasaj1 << endl;
	cout << "Pasajeri vyv vtora klasa: " << pat[i].pasaj2 << endl;
	fp.close();
}

void izvejdane_put(struct patuvania pat[], int &k) {
	system("cls");
	fstream fp;
	int n;
	int i = 0;
	double max, t;
	int ii;
	fp.open(NAME, ios::binary, ios::in);
	if (fp.fail()) {
		cout << "Greshka pri otvarqneto na faila" << endl;
		exit(1);
	}
	fp.read((char*)&pat, sizeof(patuvania));
	max = (pat[i].cena1 * pat[i].pasaj1) + (pat[i].cena2 * pat[i].pasaj2);
	for (i = 0; i < n; i++) {
		t = (pat[i].cena1 * pat[i].pasaj1) + (pat[i].cena2 * pat[i].pasaj2);
		if (max < t) {
			max = t;
			ii = i;
		}
	}
	i = ii;
	cout << "Dannite za pytuvaneto s nai-golqma obshta suma na prodadenite bileti e: " << endl;
	cout << "Ime na koryba: " << pat[i].korab << endl;
	cout << "Ime na kapitana: " << pat[i].kapitan << endl;
	cout << "Cena za pyrva klasa: " << pat[i].cena1 << endl;
	cout << "Cena za vtora klasa: " << pat[i].cena2 << endl;
	cout << "Broi pasajei v pyrva klasa: " << pat[i].pasaj1 << endl;
	cout << "Broi pasajeri vyv vtora klasa: " << pat[i].pasaj2 << endl;
	fp.close();
}
