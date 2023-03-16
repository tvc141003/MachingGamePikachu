#include <fstream>
#include <string>
using namespace std;

struct LeaderBoardType {
	double time;
	string name;
};

void getDataLeaderBoard(LeaderBoardType* leaderBoardArr, int &count, int difficulty) {

	fstream leaderBoardFile1("leaderBoardEasy.txt", ios::in);
	fstream leaderBoardFile2("leaderBoardMedium.txt", ios::in);
	fstream leaderBoardFile3("leaderBoardHard.txt", ios::in);
	

	if (!leaderBoardFile1.is_open() && !leaderBoardFile2.is_open() && !leaderBoardFile3.is_open()) {
		cout << "Can't open file" << endl;
		system("pause");
		system("cls");
		return;
	}
	count = 0;
	if (difficulty == 1)
	{
		while (!leaderBoardFile1.eof())
		{
			string temp;
			if (leaderBoardFile1 >> leaderBoardArr[count].time)
			{
				getline(leaderBoardFile1, temp, ' ');
				getline(leaderBoardFile1, leaderBoardArr[count].name, '\n');
				count++;
			}
		}
	}
	else if (difficulty == 2)
	{
		while (!leaderBoardFile2.eof())
		{
			string temp;
			if (leaderBoardFile2 >> leaderBoardArr[count].time)
			{
				getline(leaderBoardFile2, temp, ' ');
				getline(leaderBoardFile2, leaderBoardArr[count].name, '\n');
				count++;
			}
		}
	}
	else if (difficulty == 3)
	{
		while (!leaderBoardFile3.eof())
		{
			string temp;
			if (leaderBoardFile3 >> leaderBoardArr[count].time)
			{
				getline(leaderBoardFile3, temp, ' ');
				getline(leaderBoardFile3, leaderBoardArr[count].name, '\n');
				count++;
			}
		}
	}

	leaderBoardFile1.close();
	leaderBoardFile2.close();
	leaderBoardFile3.close();
}

void writeDataLeaderBoard(LeaderBoardType* leaderBoardArr, int &count, int difficulty) {
	if (difficulty == 1)
	{
		fstream leaderBoardFile("leaderBoardEasy.txt", ios::out);
		if (!leaderBoardFile.is_open()) {
			cout << "Can't open file" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < count; i++) {
			leaderBoardFile << leaderBoardArr[i].time << " ";
			if (i == count - 1) {
				leaderBoardFile << leaderBoardArr[i].name;
			}
			else {
				leaderBoardFile << leaderBoardArr[i].name << endl;
			}
		}
		leaderBoardFile.close();
	}
	else if (difficulty == 2)
	{
		fstream leaderBoardFile("leaderBoardMedium.txt", ios::out);
		if (!leaderBoardFile.is_open()) {
			cout << "Can't open file" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < count; i++) {
			leaderBoardFile << leaderBoardArr[i].time << " ";
			if (i == count - 1) {
				leaderBoardFile << leaderBoardArr[i].name;
			}
			else {
				leaderBoardFile << leaderBoardArr[i].name << endl;
			}
		}
		leaderBoardFile.close();
	}
	else if (difficulty == 3)
	{
		fstream leaderBoardFile("leaderBoardHard.txt", ios::out);
		if (!leaderBoardFile.is_open()) {
			cout << "Can't open file" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < count; i++) {
			leaderBoardFile << leaderBoardArr[i].time << " ";
			if (i == count - 1) {
				leaderBoardFile << leaderBoardArr[i].name;
			}
			else {
				leaderBoardFile << leaderBoardArr[i].name << endl;
			}
		}
		leaderBoardFile.close();
	}
}

void printLeaderBoard() {
	system("cls");

	LeaderBoardType* leaderBoardArrEasy = new LeaderBoardType[10];
	LeaderBoardType* leaderBoardArrMedium = new LeaderBoardType[10];
	LeaderBoardType* leaderBoardArrHard = new LeaderBoardType[10];

	int countEasy = 0;
	int countMedium = 0;
	int countHard = 0;
	getDataLeaderBoard(leaderBoardArrEasy, countEasy, 1);
	getDataLeaderBoard(leaderBoardArrMedium, countMedium, 2);
	getDataLeaderBoard(leaderBoardArrHard, countHard, 3);

	setColor(14);
	gotoXY(20, 0);
	cout << "             |     __  __   __|  __   _ |      __   __    _  __|   " << endl;
	gotoXY(20, 1);
	cout << "\\\\/ \\//      |    |__ |__| |  | |__ |/  |---  |  | |__| |/  |  |      \\\\/ \\//" << endl;
	gotoXY(20, 2);
	cout << " \\___/       |___ |__ |  | |__| |__ |   |___| |__| |  | |   |__|       \\___/" << endl;
	gotoXY(20, 3);
	cout << "            -----------------------------------------------------" << endl;
	setColor(7);

	setColor(14);
	gotoXY(22, 4);
	cout << "EASY";
	gotoXY(56, 4);
	cout << "MEDIUM";
	gotoXY(92, 4);
	cout << "HARD";
	setColor(7);

	gotoXY(10, 5);
	cout << " No.  Name             Time" << endl;
	gotoXY(10, 6);
	cout << "---------------------------" << endl;
	gotoXY(45, 5);
	cout << " No.  Name             Time" << endl;
	gotoXY(45, 6);
	cout << "---------------------------" << endl;
	gotoXY(80, 5);
	cout << " No.  Name             Time" << endl;
	gotoXY(80, 6);
	cout << "---------------------------" << endl;

	int space = 0;

	for (int i = 0; i < countEasy; i++) {
		if (i < 3)
		{
			if (i == 0) setColor(14);
			else if (i == 1) setColor(8);
			else setColor(6);
			gotoXY(10, 7 + space);
			cout << "\\ " << i + 1 << ". ";
			cout << " " << leaderBoardArrEasy[i].name << " ";
			for (int j = 0; j < (17 - leaderBoardArrEasy[i].name.length()); j++)
				cout << " ";
			cout << leaderBoardArrEasy[i].time << " ";
			gotoXY(10, 7 + space + 1);
			cout << " ---------------------------" << endl;
			setColor(7);
		}
		else
		{
			gotoXY(10, 7 + space);
			cout << "\\ " << i + 1 << ". ";
			if (i < 9) cout << " ";
			cout << leaderBoardArrEasy[i].name << " ";
			for (int j = 0; j < (17 - leaderBoardArrEasy[i].name.length()); j++)
				cout << " ";
			cout << leaderBoardArrEasy[i].time << " ";
			gotoXY(10, 7 + space + 1);
			cout << " ---------------------------" << endl;
		}
		space += 2;
	}

	space = 0;
	for (int i = 0; i < countMedium; i++) {
		if (i < 3)
		{
			if (i == 0) setColor(14);
			else if (i == 1) setColor(8);
			else setColor(6);
			gotoXY(45, 7 + space);
			cout << "\\ " << i + 1 << ". ";
			cout << " " << leaderBoardArrMedium[i].name << " ";
			for (int j = 0; j < (17 - leaderBoardArrMedium[i].name.length()); j++)
				cout << " ";
			cout << leaderBoardArrMedium[i].time << " ";
			gotoXY(45, 7 + space + 1);
			cout << " ---------------------------" << endl;
			setColor(7);
		}
		else
		{
			gotoXY(45, 7 + space);
			cout << "\\ " << i + 1 << ". ";
			if (i < 9) cout << " ";
			cout << leaderBoardArrMedium[i].name << " ";
			for (int j = 0; j < (17 - leaderBoardArrMedium[i].name.length()); j++)
				cout << " ";
			cout << leaderBoardArrMedium[i].time << " ";
			gotoXY(45, 7 + space + 1);
			cout << " ---------------------------" << endl;
		}
		space += 2;
	}

	space = 0;
	for (int i = 0; i < countHard; i++) {
		if (i < 3)
		{
			if (i == 0) setColor(14);
			else if (i == 1) setColor(8);
			else setColor(6);
			gotoXY(80, 7 + space);
			cout << "\\ " << i + 1 << ". ";
			cout << " " << leaderBoardArrHard[i].name << " ";
			for (int j = 0; j < (17 - leaderBoardArrHard[i].name.length()); j++)
				cout << " ";
			cout << leaderBoardArrHard[i].time << " ";
			gotoXY(80, 7 + space + 1);
			cout << " ---------------------------" << endl;
			setColor(7);
		}
		else
		{
			gotoXY(80, 7 + space);
			cout << "\\ " << i + 1 << ". ";
			if (i < 9) cout << " ";
			cout << leaderBoardArrHard[i].name << " ";
			for (int j = 0; j < (17 - leaderBoardArrHard[i].name.length()); j++)
				cout << " ";
			cout << leaderBoardArrHard[i].time << " ";
			gotoXY(80, 7 + space + 1);
			cout << " ---------------------------" << endl;
		}
		space += 2;
	}


	delete[] leaderBoardArrEasy;
	delete[] leaderBoardArrMedium;
	delete[] leaderBoardArrHard;
	gotoXY(43, 27);
	system("pause");
	system("cls");
}

void addLeaderBoard(LeaderBoardType user, int difficulty) {
	LeaderBoardType* leaderBoardArr = new LeaderBoardType[10];
	int count = 0;

	getDataLeaderBoard(leaderBoardArr, count, difficulty);

	if (count < 10) {
		count++;
		//leaderBoardArr[count - 1] = leaderBoardArr[count - 2];
	}

	int posLeaderBoard = count - 1;
	while (posLeaderBoard > 0 && leaderBoardArr[posLeaderBoard - 1].time > user.time) {
		leaderBoardArr[posLeaderBoard] = leaderBoardArr[posLeaderBoard - 1];
		posLeaderBoard--;
		cout << leaderBoardArr[posLeaderBoard].time << endl;
	}
	leaderBoardArr[posLeaderBoard].time = user.time;
	leaderBoardArr[posLeaderBoard].name = user.name;

	writeDataLeaderBoard(leaderBoardArr, count, difficulty);
	printLeaderBoard();
}

bool checkTopPlayer(double totalTime, int difficulty) {
	LeaderBoardType* leaderBoardArr = new LeaderBoardType[10];
	int count = 0;

	getDataLeaderBoard(leaderBoardArr, count, difficulty);
	if (count < 10 || leaderBoardArr[9].time > totalTime) return true;
	return false;
}