#include "Game.h"
using namespace std;

int getUserEnterPos(int& x) {

	do {
		int pos = _getch();
		switch (pos) {
		case (119): { //w
			int oldPos = x;
			x -= 3;
			if (x < 17) x = 17;
			renderPosMenu(oldPos, 14);
			renderPosMenu(x, 206);
			break;
		}
		case (87): { //W
			int oldPos = x;
			x -= 3;
			if (x < 17) x = 17;
			renderPosMenu(oldPos, 14);
			renderPosMenu(x, 206);
			break;
		}
		case (115): { //s
			int oldPos = x;
			x += 3;
			if (x > 26) x = 26;
			renderPosMenu(oldPos, 14);
			renderPosMenu(x, 206);
			break;
		}
		case (83): { //S
			int oldPos = x;
			x += 3;
			if (x > 26) x = 26;
			renderPosMenu(oldPos, 14);
			renderPosMenu(x, 206);
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

void mainMenu() {

	MainMenu();
	Pikachu();
	int difficulty = 0;
	setColor(7);

	int j = 17;
	renderPosMenu(j, 206);
	do {
		j = getUserEnterPos(j);
		switch (j) {
		case (17): {
			game(1, difficulty);
			mainMenu();
			break;
		}
		case (20): {
			game(2, difficulty);
			mainMenu();
			break;
		}
		case (23): {
			printLeaderBoard();
			mainMenu();
			break;
		}
		case (26): {
			system("cls");
			Ending();
			gotoXY(0, 27);
			exit(0);
			break;
		}
		}
	} while (1);
}

int main() {

	srand((int)time(0));
	system("cls");
	ScreenSize(1000, 1000);
	mainMenu();

	return 0;
}
