//POP_2019_12_09_projekt_1_Ksawery_Armatyñski_EiT_3_180088

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<time.h>
#include<stdlib.h>


using namespace std;

const int MAX_M = 22;
const int MAX_N = 62;
int Tab[MAX_M][MAX_N];


void krawedzPoz();

int prawdopodobienstwo(int&);

void generowanie(int, int[][MAX_N]);

void wyswietlanieTab(int[][MAX_N]);

void menu(int);

void czyszczenie();

void resetowanie(int[][MAX_N]);

void krokSymulacji(int[][MAX_N]);

void przezycie(int[][MAX_N], int[][MAX_N], int, int);

void narodziny(int[][MAX_N], int[][MAX_N], int, int);


int main()
{
	int n;

	n = prawdopodobienstwo(n);

	generowanie(n, Tab);
	wyswietlanieTab(Tab);

	menu(n);

	system("PAUSE");
	return 0;
}

void krawedzPoz() {
	char znak = '-', rog = '+';
	cout << rog;
	for (int i = 0; i < MAX_N-2; i++)
		cout << znak;
	cout << rog << endl;
}

int prawdopodobienstwo(int& n) {
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "Podaj szanse z jaka maja pojawiac sie bakterie z przedzialu od 0 do 100(0%-100%)" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	while (!(cin >> n) or (n < 0 or n > 100)) {
		cin.clear();
		cin.ignore(200, '\n');
		cerr << "------------------------------------------" << endl
			 << "Bledne dane - podaj liczbe od 0 do 100 !!!" << endl
			 << "------------------------------------------" << endl;
		system("PAUSE");
		czyszczenie();
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "Podaj szanse z jaka maja pojawiac sie bakterie z przedzialu od 0 do 100(0%-100%)" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
	}

	return n;
}

void generowanie(int n, int Tab[][MAX_N]) {
	int liczba;
	srand(time(NULL));

	for (int i = 0; i < MAX_M; i++) {
		for (int j = 0; j < MAX_N; j++) {
			liczba = rand() % 101;
			if (i == 0 or j == 0 or i == MAX_M - 1 or j == MAX_N - 1) Tab[i][j] = 2;
			else if (liczba <= n && n != 0) Tab[i][j] = 1;
			else Tab[i][j] = 0;
		}
	}
}

void wyswietlanieTab(int Tab[][MAX_N]) {
	krawedzPoz();
	char bakteria = 'o';
	char pusto = ' ';
	char bok = '|';
	int x = 0;
	for (int i = 1; i < MAX_M-1; i++) {
		cout << bok;
		for (int j = 1; j < MAX_N-1; j++) {
			if (Tab[i][j] == 2) cout << Tab[i][j];
			if (Tab[i][j] == 1) { cout << bakteria, x++; }
			if (Tab[i][j] == 0) cout << pusto;
		}
		cout << bok << endl;
	}
	krawedzPoz();
	cout << "[Ile bakterii: " << x << "]" << endl;
}

void czyszczenie() {
	system("cls");
}

void menu(int n) {
	char z = 'a';
	while (z != 'Q') {
		cout << "R - reset, Q - koniec, kazdy inny klawisz - krok symulacji" << endl;
		cin >> z;

		if (z == 'R' or z == 'r') {
			resetowanie(Tab);
		}
		else if (z == 'Q' or z == 'q') {
			break;
			system("PAUSE");
		}
		else krokSymulacji(Tab);
	}
}

void resetowanie(int Tab[][MAX_N]) {
	int x;
	czyszczenie();
	x = prawdopodobienstwo(x);
	generowanie(x, Tab);
	wyswietlanieTab(Tab);
}

void krokSymulacji(int Tab[][MAX_N]) {
	int z = 0;
	int Tab1[MAX_M][MAX_N];
	for (int i = 1; i < MAX_M-1; i++) {
		for (int j = 1; j < MAX_N-1; j++) {
			if (Tab[i][j] == 0) narodziny(Tab1, Tab, i, j);
			if (Tab[i][j] == 1) przezycie(Tab1, Tab, i, j);
		}
	}

	for (int i = 1; i < MAX_M-1; i++) {
		for (int j = 1; j < MAX_N-1; j++) {
			Tab[i][j] = Tab1[i][j];
		}
	}
	czyszczenie();
	wyswietlanieTab(Tab);
}

void przezycie(int Tab1[][MAX_N], int Tab[][MAX_N], int x, int y) {
	int k = 0;

		if (Tab[x][y + 1] == 1) k++;
		if (Tab[x][y - 1] == 1) k++;
		if (Tab[x + 1][y] == 1) k++;
		if (Tab[x - 1][y] == 1) k++;
		if (Tab[x + 1][y + 1] == 1) k++;
		if (Tab[x - 1][y + 1] == 1) k++;
		if (Tab[x + 1][y - 1] == 1) k++;
		if (Tab[x - 1][y - 1] == 1) k++;

		if (k == 2 or k == 3) Tab1[x][y] = 1;
		if (k != 2 && k != 3) Tab1[x][y] = 0;
	
}

void narodziny(int Tab1[][MAX_N], int Tab[][MAX_N], int x, int y) {
	int k = 0;
	
		if (Tab[x][y + 1] == 1) k++;
		if (Tab[x][y - 1] == 1) k++;
		if (Tab[x + 1][y] == 1) k++;
		if (Tab[x - 1][y] == 1) k++;
		if (Tab[x + 1][y + 1] == 1) k++;
		if (Tab[x - 1][y + 1] == 1) k++;
		if (Tab[x + 1][y - 1] == 1) k++;
		if (Tab[x - 1][y - 1] == 1) k++;

		if (k == 3) Tab1[x][y] = 1;
		if (k != 3) Tab1[x][y] = 0;
}







