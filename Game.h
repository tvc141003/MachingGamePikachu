#include <conio.h>
#include <ctime>
#include <string>
#include "drawConsole.h"
#include "gameFunction.h"
#include "leaderBoard.h"
using namespace std;

int aKey(int** Pika, int n, int m, int x, int y) {
	y--;
	if (y == 0) y++;

	return y;
}

int sKey(int** Pika, int n, int m, int x, int y) {
	x++;
	if (x == n + 1) x--;

	return x;
}

int dKey(int** Pika, int n, int m, int x, int y) {
	y++;
	if (y == m + 1) y--;

	return y;
}

int wKey(int** Pika, int n, int m, int x, int y) {
	x--;
	if (x == 0) x++;
	return x;
}

Point getUserEnterPoint(int** Pika, int n, int m, int& i, int& j, Point s) {

	Point returnValue;

	do {
		if (i != s.x || j != s.y) renderConsole(j * 10, i * 5, Pika[i][j], 112);

		int c = _getch();
		switch (c) {
		case (97): { //a
			int oldJ = j;
			j = aKey(Pika, n, m, i, j);
			if (i != s.x || j != s.y) {
				if (i != s.x || oldJ != s.y) renderConsole(oldJ * 10, i * 5, Pika[i][oldJ], 7); //Tra lai mau cu o toa do cu
				renderConsole(j * 10, i * 5, Pika[i][j], 112); //Tao mau moi tai o dang dung
			}
			else {
				renderConsole(oldJ * 10, i * 5, Pika[i][oldJ], 7);
				gotoXY((20 * j + 6) / 2 + 1, (10 * i + 3) / 2 + 1);
			}
			break;
		}
		case (65): { //A
			int oldJ = j;
			j = aKey(Pika, n, m, i, j);
			if (i != s.x || j != s.y) {
				if (i != s.x || oldJ != s.y) renderConsole(oldJ * 10, i * 5, Pika[i][oldJ], 7); //Tra lai mau cu o toa do cu
				renderConsole(j * 10, i * 5, Pika[i][j], 112); //Tao mau moi tai o dang dung
			}
			else {
				renderConsole(oldJ * 10, i * 5, Pika[i][oldJ], 7);
				gotoXY((20 * j + 6) / 2 + 1, (10 * i + 3) / 2 + 1);
			}
			break;
		}
		case (115): { //s
			int oldI = i;
			i = sKey(Pika, n, m, i, j);
			if (i != s.x || j != s.y) {
				if (oldI != s.x || j != s.y) renderConsole(j * 10, oldI * 5, Pika[oldI][j], 7);
				renderConsole(j * 10, i * 5, Pika[i][j], 112);
			}
			else {
				renderConsole(j * 10, oldI * 5, Pika[oldI][j], 7);
				gotoXY((20 * j + 6) / 2 + 1, (10 * i + 3) / 2 + 1);
			}
			break;
		}
		case (83): { //S
			int oldI = i;
			i = sKey(Pika, n, m, i, j);
			if (i != s.x || j != s.y) {
				if (oldI != s.x || j != s.y) renderConsole(j * 10, oldI * 5, Pika[oldI][j], 7);
				renderConsole(j * 10, i * 5, Pika[i][j], 112);
			}
			else {
				renderConsole(j * 10, oldI * 5, Pika[oldI][j], 7);
				gotoXY((20 * j + 6) / 2 + 1, (10 * i + 3) / 2 + 1);
			}
			break;
		}
		case (100): { //d
			int oldJ = j;
			j = dKey(Pika, n, m, i, j);
			if (i != s.x || j != s.y) {
				if (i != s.x || oldJ != s.y) renderConsole(oldJ * 10, i * 5, Pika[i][oldJ], 7);
				renderConsole(j * 10, i * 5, Pika[i][j], 112);
			}
			else {
				renderConsole(oldJ * 10, i * 5, Pika[i][oldJ], 7);
				gotoXY((20 * j + 6) / 2 + 1, (10 * i + 3) / 2 + 1);
			}
			break;
		}
		case (68): { //D
			int oldJ = j;
			j = dKey(Pika, n, m, i, j);
			if (i != s.x || j != s.y) {
				if (i != s.x || oldJ != s.y) renderConsole(oldJ * 10, i * 5, Pika[i][oldJ], 7);
				renderConsole(j * 10, i * 5, Pika[i][j], 112);
			}
			else {
				renderConsole(oldJ * 10, i * 5, Pika[i][oldJ], 7);
				gotoXY((20 * j + 6) / 2 + 1, (10 * i + 3) / 2 + 1);
			}
			break;
		}
		case (119): { //w
			int oldI = i;
			i = wKey(Pika, n, m, i, j);
			if (i != s.x || j != s.y) {
				if (oldI != s.x || j != s.y) renderConsole(j * 10, oldI * 5, Pika[oldI][j], 7);
				renderConsole(j * 10, i * 5, Pika[i][j], 112);
			}
			else {
				renderConsole(j * 10, oldI * 5, Pika[oldI][j], 7);
				gotoXY((20 * j + 6) / 2 + 1, (10 * i + 3) / 2 + 1);
			}
			break;
		}
		case (87): { //W
			int oldI = i;
			i = wKey(Pika, n, m, i, j);
			if (i != s.x || j != s.y) {
				if (oldI != s.x || j != s.y) renderConsole(j * 10, oldI * 5, Pika[oldI][j], 7);
				renderConsole(j * 10, i * 5, Pika[i][j], 112);
			}
			else {
				renderConsole(j * 10, oldI * 5, Pika[oldI][j], 7);
				gotoXY((20 * j + 6) / 2 + 1, (10 * i + 3) / 2 + 1);
			}
			break;
		}
		case (104): { //h
			moveSuggestion(Pika, n, m, s);
			break;
		}
		case (72): { //H
			moveSuggestion(Pika, n, m, s);
			break;
		}
		case (13): { //enter
			returnValue.x = i;
			returnValue.y = j;
			if (Pika[i][j] != -1) {
				return returnValue;
			}
			else continue;
			break;
		}
		default: continue;
		}
	} while (1);

	return returnValue;
}

int getUserChoice(int& x)
{
	do {
		int pos = _getch();
		switch (pos) {
		case (119): { //w
			int oldPos = x;
			x -= 3;
			if (x < 9) x = 9;
			renderChoiceMenu(oldPos, 14);
			renderChoiceMenu(x, 30);
			break;
		}
		case (87): { //W
			int oldPos = x;
			x -= 3;
			if (x < 9) x = 9;
			renderChoiceMenu(oldPos, 14);
			renderChoiceMenu(x, 30);
			break;
		}
		case (115): { //s
			int oldPos = x;
			x += 3;
			if (x > 12) x = 12;
			renderChoiceMenu(oldPos, 14);
			renderChoiceMenu(x, 30);
			break;
		}
		case (83): { //S
			int oldPos = x;
			x += 3;
			if (x > 12) x = 12;
			renderChoiceMenu(oldPos, 14);
			renderChoiceMenu(x, 30);
			break;
		}
		case (13): {
			return x;
			break;
		}
		default: break;
		}
	} while (1);
}

int getDifficulty(int& x)
{
	do {
		int pos = _getch();
		switch (pos) {
		case (97): { //a
			int oldPos = x;
			x -= 21;
			if (x < 31) x = 31;
			renderDifficulty(oldPos, 14);
			renderDifficulty(x, 23);
			break;
		}
		case (65): { //A
			int oldPos = x;
			x -= 21;
			if (x < 31) x = 31;
			renderDifficulty(oldPos, 14);
			renderDifficulty(x, 23);
			break;
		}
		case (100): { //d
			int oldPos = x;
			x += 21;
			if (x > 73) x = 73;
			renderDifficulty(oldPos, 14);
			renderDifficulty(x, 23);
			break;
		}
		case (68): { //D
			int oldPos = x;
			x += 21;
			if (x > 73) x = 73;
			renderDifficulty(oldPos, 14);
			renderDifficulty(x, 23);
			break;
		}
		case (13): {
			return x;
			break;
		}
		default: break;
		}
	} while (1);

}

void GameMode(int &m, int &n, int &difficulty)
{
	system("cls");
	setColor(14);
	gotoXY(48, 0);
	cout << "        ___   __    ___" << endl;
	gotoXY(48, 1);
	cout << "|\\  /| |   | |  \\  |   " << endl;
	gotoXY(48, 2);
	cout << "| \\/ | |   | |   | |---" << endl;
	gotoXY(48, 3);
	cout << "|    | |___| |__/  |___" << endl;

	gotoXY(25, 5);
	cout << " ------------------------------------------------------------------" << endl;
	gotoXY(25, 6);
	cout << "|                                                                  |" << endl;
	gotoXY(25, 7);
	cout << "|                                                                  |" << endl;
	gotoXY(25, 8);
	cout << "|     --------------       --------------       --------------     |" << endl;
	gotoXY(25, 9);
	cout << "|    |     Easy     |     |    Medium    |     |     Hard     |    |" << endl;
	gotoXY(25, 10);
	cout << "|     --------------       --------------       --------------     |" << endl;
	gotoXY(25, 11);
	cout << "|                                                                  |" << endl;
	gotoXY(25, 12);
	cout << " ------------------------------------------------------------------" << endl;

	Mode_Image();

	setColor(7);

	int y = 31;
	renderDifficulty(y, 23);
	getDifficulty(y);

	/*	system("cls");
	char s[100] = "                            ";
	gotoXY(40, 12);
	cout << "Loading: ";
	for (int i = 0; s[i] != '\0'; i++)
	{
		Sleep(50);
		setColor(23);
		cout << s[i];
	}
	*/

	setColor(7);


	if (y == 31)
	{
		n = 2; m = 3;
		difficulty = 1;
	}
	else if (y == 52)
	{
		n = 3, m = 4;
		difficulty = 2;
	}
	else if (y == 73) 
	{
		n = 4, m = 6;
		difficulty = 3;
	}
}

void CustomPlay(int& m, int& n)
{
	system("cls");
	setColor(14);
	gotoXY(47, 5);
	cout << "-----------------------" << endl;
	gotoXY(47, 11);
	cout << "-----------------------" << endl;
	gotoXY(50, 6);
	cout << "- CUSTOM BOARD -" << endl;
	gotoXY(50, 8);
	cout << "Input rows: ";
	cin >> n;
	gotoXY(50, 9);
	cout << "Input columns: ";
	cin >> m;
	cout << endl << endl;
	char s[100] = "               ";
	gotoXY(50, 12);
	cout << "Generating board";
	gotoXY(50, 13);
	for (int i = 0; s[i] != '\0'; i++)
	{
		Sleep(100);
		setColor(23);
		cout << s[i];
	}
	setColor(7);

}

void playGame(int** Pika, int n, int m, int choice, int difficulty) {
	system("cls");

	if (choice == 1) {
		setColor(9);
		gotoXY(0, 0);
		cout << " ======================================================================================================================";
		gotoXY(0, 28);
		cout << " ======================================================================================================================";
		for (int i = 1; i < 28; i++)
		{
			gotoXY(0, i);
			cout << "||";
			gotoXY(78, i);
			cout << "||";
			gotoXY(118, i);
			cout << "||";
		}
		setColor(12);
		Play_Image();
		setColor(14);
		if (difficulty == 1) {
			gotoXY(91, 5);
			cout << " __  _   _  _ _ ";
			gotoXY(91, 6);
			cout << "|__ |_| |_` |_| ";
			gotoXY(91, 7);
			cout << "|__ | |  _|  |  ";
		}
		else if (difficulty == 2) {
			gotoXY(87, 5);
			cout << "      __  _            ";
			gotoXY(87, 6);
			cout << "|\\/| |__ | \\ | | | |\\/|";
			gotoXY(87, 7);
			cout << "|  | |__ |_/ | |_/ |  |";
		}
		else if (difficulty == 3) {
			gotoXY(91, 5);
			cout << "     _   _   _ ";
			gotoXY(91, 6);
			cout << "|_| |_| |_| | \\";
			gotoXY(91, 7);
			cout << "| | | | | \\ |_/ ";
		}

		setColor(7);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (Pika[i][j] != -1) renderConsole(j * 10, i * 5, Pika[i][j], 7);
	}
	cout << endl << endl << endl;

	int i = 1, j = 1;
	time_t beginGame = time(NULL);
	while (!checkEndGame(Pika, n, m)) {
		//system("pause");
		if (!checkEndGame(Pika, n, m) && checkNotPath(Pika, n, m)) {
			randomGame(Pika, n, m);
			system("cls");

			if (choice == 1) {
				setColor(9);
				gotoXY(0, 0);
				cout << "========================================================================================================================";
				gotoXY(0, 28);
				cout << "========================================================================================================================";
				for (int i = 1; i < 28; i++)
				{
					gotoXY(0, i);
					cout << "||";
					gotoXY(78, i);
					cout << "||";
					gotoXY(118, i);
					cout << "||";
				}
				setColor(12);
				Play_Image();
				setColor(14);
				if (difficulty == 1) {
					gotoXY(91, 5);
					cout << " __  _   _  _ _ ";
					gotoXY(91, 6);
					cout << "|__ |_| |_` |_| ";
					gotoXY(91, 7);
					cout << "|__ | |  _|  |  ";
				}
				else if (difficulty == 2) {
					gotoXY(87, 5);
					cout << "      __  _            ";
					gotoXY(87, 6);
					cout << "|\\/| |__ | \\ | | | |\\/|";
					gotoXY(87, 7);
					cout << "|  | |__ |_/ | |_/ |  |";
				}
				else if (difficulty == 3) {
					gotoXY(91, 5);
					cout << "     _   _   _ ";
					gotoXY(91, 6);
					cout << "|_| |_| |_| | \\";
					gotoXY(91, 7);
					cout << "| | | | | \\ |_/ ";
				}

				setColor(7);
			}

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++)
					if (Pika[i][j] != -1) renderConsole(j * 10, i * 5, Pika[i][j], 7);
			}
			continue;
		}

		Point s, t;
		Point userEnterPos;
		s.x = -1;
		s.y = -1;
		userEnterPos = getUserEnterPoint(Pika, n, m, i, j, s);
		s = userEnterPos;
		renderConsole(s.y * 10, s.x * 5, Pika[s.x][s.y], 59);
		do {
			userEnterPos = getUserEnterPoint(Pika, n, m, i, j, s);
			t = userEnterPos;
		} while (t.x == s.x && t.y == s.y);
		renderConsole(t.y * 10, t.x * 5, Pika[t.x][t.y], 59);
		Sleep(100);

		//if (Pika[s.x][s.y] != Pika[t.x][t.y]) continue;

		if (getPathValue(s, t, Pika, n, m) && Pika[s.x][s.y] == Pika[t.x][t.y]) {
			renderConsole(s.y * 10, s.x * 5, Pika[s.x][s.y], 47);
			renderConsole(t.y * 10, t.x * 5, Pika[t.x][t.y], 47);
			Sleep(100);
			Pika[s.x][s.y] = -1;
			Pika[t.x][t.y] = -1;

			renderConsole(s.y * 10, s.x * 5, Pika[s.x][s.y], 7);
			renderConsole(t.y * 10, t.x * 5, Pika[t.x][t.y], 7);
		}
		else {
			renderConsole(s.y * 10, s.x * 5, Pika[s.x][s.y], 71);
			renderConsole(t.y * 10, t.x * 5, Pika[t.x][t.y], 71);
			Sleep(100);
			renderConsole(s.y * 10, s.x * 5, Pika[s.x][s.y], 7);
			renderConsole(t.y * 10, t.x * 5, Pika[t.x][t.y], 7);
		}
	}
	time_t endGame = time(NULL);

	if (choice == 1)
	{
		double totalTime = endGame - beginGame;
		if (checkTopPlayer(totalTime, difficulty)) {

			setColor(14);
			gotoXY(30, 5);
			cout << " -------------------------------------------------------------";
			gotoXY(30, 6);
			cout << "| You got a high score! Do you want to be on the leaderboard? |" << endl;
			gotoXY(30, 7);
			cout << "|                          ---------                          |" << endl;
			gotoXY(30, 8);
			cout << "|                         |   Yes   |                         |" << endl;
			gotoXY(30, 9);
			cout << "|                          ---------                          |" << endl;
			gotoXY(30, 10);
			cout << "|                          ---------                          |" << endl;
			gotoXY(30, 11);
			cout << "|                         |   No    |                         |" << endl;
			gotoXY(30, 12);
			cout << "|                          ---------                          |" << endl;
			gotoXY(30, 13);
			cout << " -------------------------------------------------------------";
			int i = 9;
			renderChoiceMenu(i, 30);
			setColor(7);

			i = getUserChoice(i);
			switch (i) {
			case (9): {
				system("cls");
				LeaderBoardType user;
				user.time = totalTime;
				setColor(14);
				gotoXY(48, 5);
				cout << "-----------------------";
				gotoXY(48, 8);
				cout << "-----------------------";
				gotoXY(47, 6);
				cout << "|";
				gotoXY(47, 7);
				cout << "|";
				gotoXY(71, 6);
				cout << "|";
				gotoXY(71, 7);
				cout << "|";

				gotoXY(51, 6);
				cout << "Enter your name: ";
				gotoXY(51, 7);
				setColor(9);
				getline(cin, user.name);
				setColor(7);
				cout << endl;
				addLeaderBoard(user, difficulty);
				break;
			}
			case (12): {
				system("cls");
				break;
			}
			}

	}
	}
	else return;
}

void game(int choice, int &difficulty) {
	int n, m;
	do {
		if (choice == 1)
		{
			GameMode(m,n,difficulty);
		}
		if (choice == 2)
		{
			CustomPlay(m,n);
		}

	} while ((n * m) % 2 != 0 || n > 100 || m > 100 || n < 1 || m < 1);

	int** Pika = new int* [n + 2];
	for (int i = 0; i < n + 2; i++) Pika[i] = new int[m + 2];
	for (int i = 0; i < n + 2; i++)
		for (int j = 0; j < m + 2; j++) Pika[i][j] = -1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (Pika[i][j] == -1) {
				char k = rand() % 26 + 65;
				Pika[i][j] = char(k);
				int subN, subM;
				do {
					subN = rand() % n + 1;
					subM = rand() % m + 1;
				} while (Pika[subN][subM] != -1);
				Pika[subN][subM] = k;
			}
	playGame(Pika, n, m, choice, difficulty);
	for (int i = 0; i < n + 2; i++) delete[] Pika[i];
	delete[] Pika;
}

void Ending()
{
	gotoXY(30, 8);
	char line[100] = "----------------------------------------------------------------";
	Text_Animation(line);
	cout << endl;

	gotoXY(30, 9);
	char thank[100] = "                     Thanks for playing                          ";
	Text_Animation(thank);
	cout << endl;

	gotoXY(30, 10);
	setColor(12);
	char a[100] = "                   __                                            ";
	Text_Animation(a);
	cout << endl;

	gotoXY(30, 11);
	char b[100] = " __ __     _____  |  | __  ____   __ ___  ____   _____   __ ___  ";
	Text_Animation(b);
	cout << endl;

	setColor(14);
	gotoXY(30, 12);
	char c[100] = "|  '_  \\  /  _  \\ |  |/ / /  _ \\ |  '_  ' _   \\ /  _  \\ |  '_  \\ ";
	Text_Animation(c);
	cout << endl;

	setColor(10);
	gotoXY(30, 13);
	char d[100] = "|  |_)  ||  (_)  ||    < |  ___/ |  | |  | |  ||  (_)  ||  | |  |";
	Text_Animation(d);
	cout << endl;

	setColor(11);
	gotoXY(30, 14);
	char e[100] = "|  .___/  \\_____/ |__|\\_\\ \\____| |__| |__| |__| \\_____/ |__| |__|";
	Text_Animation(e);
	cout << endl;

	setColor(9);
	gotoXY(30, 15);
	char f[100] = "|__|                                                             ";
	Text_Animation(f);
	cout << endl;

	setColor(7);
	gotoXY(30, 16);
	Text_Animation(line);
	cout << endl;
}
