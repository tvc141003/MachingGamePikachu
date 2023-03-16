#include <Windows.h>
#include <iostream>
#include <fstream>
using namespace std;

HANDLE hStdin;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void ScreenSize(int x, int y) {

	CursorPosition.X = x;
	CursorPosition.Y = y;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = x - 1;
	Rect.Right = y - 1;

	SetConsoleScreenBufferSize(console, CursorPosition);
	SetConsoleWindowInfo(console, TRUE, &Rect);

}

void gotoXY(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void setColor(int color) {
	SetConsoleTextAttribute(console, color);
}

void renderConsole(int x, int y, int k, int color) {
	gotoXY((2 * x + 6) / 2 + 1, (2 * y + 3) / 2 + 1);
	if (k != -1) {
		setColor(color);
		for (int i = 1; i < 8; i++) {
			gotoXY(x + i, y);
			cout << '-';
			gotoXY(x + i, y + 4);
			cout << '-';
		}

		for (int i = 1; i < 4; i++) {
			gotoXY(x, y + i);
			cout << '|';
			gotoXY(x + 8, y + i);
			cout << '|';
		}

		gotoXY(x + 1, y + 1);
		for (int i = 2; i <= 4; i++) {
			for (int j = 1; j <= 7; j++) cout << " ";
			gotoXY(x + 1, y + i);
		}

		gotoXY((2 * x + 6) / 2 + 1, (2 * y + 3) / 2 + 1);
		cout << char(k);
		setColor(7);
	}
	else {
		for (int i = 1; i < 8; i++) {
			gotoXY(x + i, y);
			cout << ' ';
			gotoXY(x + i, y + 4);
			cout << ' ';
		}

		for (int i = 1; i < 4; i++) {
			gotoXY(x, y + i);
			cout << ' ';
			gotoXY(x + 8, y + i);
			cout << ' ';
		}
		gotoXY(x + 1, y + 1);
		for (int i = 2; i <= 4; i++) {
			for (int j = 1; j <= 7; j++) cout << " ";
			gotoXY(x + 1, y + i);
		}
	}
	gotoXY((2 * x + 6) / 2 + 1, (2 * y + 3) / 2 + 1);
}

void renderPosMenu(int y, int color) {
	setColor(color);
	gotoXY(45, y - 4);
	if (y == 17) cout << " " << y - 16 << '.' << " Play                  ";
	else if (y == 20) cout << " " << y - 18 << '.' << " Custom play           ";
	else if (y == 23) cout << " " << y - 20 << '.' << " Leaderboard           ";
	else if (y == 26) cout << " " << y - 22 << '.' << " Exit                  ";
	gotoXY(46, y - 4);
	setColor(7);
}

void renderChoiceMenu(int y, int color)
{
	setColor(color);
	gotoXY(57, y - 1);
	if (y == 9) cout << "   Yes   ";
	else if (y == 12) cout << "   No    ";
	gotoXY(57, y - 1);
	setColor(7);
}

void renderDifficulty(int y, int color)
{
	setColor(color);
	gotoXY(y, 9);
	if (y == 31) cout << "     Easy     ";
	else if (y == 52) cout << "    Medium    ";
	else if (y == 73) cout << "     Hard     ";
	gotoXY(y, 9);
	setColor(7);
}

void Text_Animation(char a[100])
{
	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
		Sleep(1);
		cout << a[i];
	}
}

void MainMenu()
{
	cout << endl << endl << endl;
	setColor(12);
	cout << "                                            __                                            " << endl;
	cout << "                          __ __     _____  |  | __  ____   __ ___  ____   _____   __ ___  " << endl;
	setColor(14);
	cout << "                         |  '_  \\  /  _  \\ |  |/ / /  _ \\ |  '_  ' _   \\ /  _  \\ |  '_  \\ " << endl;
	setColor(10);
	cout << "                         |  |_)  ||  (_)  ||    < |  ___/ |  | |  | |  ||  (_)  ||  | |  |" << endl;
	setColor(11);
	cout << "                         |  .___/  \\_____/ |__|\\_\\ \\____| |__| |__| |__| \\_____/ |__| |__|" << endl;
	setColor(9);
	cout << "                         |__|                                                             " << endl;
	setColor(7);
	cout << endl << endl << endl;
	setColor(14);

	gotoXY(43, 12);
	cout << " ---------------------------" << endl;
	gotoXY(43, 13);
	cout << "|  1. Play                  |" << endl;
	gotoXY(43, 14);
	cout << " ---------------------------" << endl;
	gotoXY(43, 15);
	cout << " ---------------------------" << endl;
	gotoXY(43, 16);
	cout << "|  2. Custom play           |" << endl;
	gotoXY(43, 17);
	cout << " ---------------------------" << endl;
	gotoXY(43, 18);
	cout << " ---------------------------" << endl;
	gotoXY(43, 19);
	cout << "|  3. Leaderboard           |" << endl;
	gotoXY(43, 20);
	cout << " ---------------------------" << endl;
	gotoXY(43, 21);
	cout << " ---------------------------" << endl;
	gotoXY(43, 22);
	cout << "|  4. Exit                  |" << endl;
	gotoXY(43, 23);
	cout << " ---------------------------" << endl;
}

void Pikachu()
{
	ifstream pika1("pikachu1.txt");
	ifstream pika2("pikachu2.txt");

	string s;
	int x = 9, y = 11;
	int u = 82, v = 11;
	while (!pika1.eof())
	{
		gotoXY(x, y++);
		getline(pika1, s, '\n');
		cout << s;
		gotoXY(u, v++);
		getline(pika2, s, '\n');
		cout << s;
		//Sleep(100);
	}

	pika1.close();
	pika2.close();
}

void Mode_Image()
{
	ifstream pika3("pikachu3.txt");

	string s;
	int x = 37, y = 15;
	while (!pika3.eof())
	{
		gotoXY(x, y++);
		getline(pika3, s, '\n');
		cout << s;
	}
	pika3.close();
}

void Play_Image() {
	ifstream pika4("pikachu4.txt");

	string s;
	int x = 84, y = 15;
	while (!pika4.eof())
	{
		gotoXY(x, y++);
		getline(pika4, s, '\n');
		cout << s;
	}
	pika4.close();
}