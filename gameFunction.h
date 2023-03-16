#include <synchapi.h>
#include "Queue.h"
using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

bool isInsideArr(Point point, int n, int m) {
	if (point.x >= 0 && point.x < n && point.y >= 0 && point.y < m) return true;
	return false;
}

bool getPathValue(Point s, Point t, int** Pika, int n, int m) {
	int** subArr = new int* [n + 2];
	for (int i = 0; i < n + 2; i++) subArr[i] = new int[m + 2];
	n = n + 2;
	m = m + 2;

	Queue q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) subArr[i][j] = 4;

	subArr[s.x][s.y] = 1;
	Path temp;
	temp.coordinates.x = s.x;
	temp.coordinates.y = s.y;
	temp.value = 1;
	temp.trace.x = -1;
	temp.trace.y = -1;
	q.push(temp);

	while (!q.empty()) {
		Path curPoint = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			Point nextPoint;
			nextPoint.x = curPoint.coordinates.x + dx[i];
			nextPoint.y = curPoint.coordinates.y + dy[i];


			if (nextPoint.x != t.x || nextPoint.y != t.y)
				if (!isInsideArr(nextPoint, n, m) || Pika[nextPoint.x][nextPoint.y] != -1) continue;

			Path addQueue;
			addQueue.coordinates.x = nextPoint.x;
			addQueue.coordinates.y = nextPoint.y;

			addQueue.trace.x = curPoint.coordinates.x;
			addQueue.trace.y = curPoint.coordinates.y;

			if (curPoint.trace.x == -1 || curPoint.trace.y == -1) {
				addQueue.value = curPoint.value;

				if (addQueue.value <= subArr[nextPoint.x][nextPoint.y]) {
					subArr[nextPoint.x][nextPoint.y] = addQueue.value;
					q.push(addQueue);
				}
			}
			else {
				if (nextPoint.x == curPoint.trace.x && nextPoint.y == curPoint.trace.y) continue;
				else if (nextPoint.x == curPoint.trace.x || nextPoint.y == curPoint.trace.y) {
					addQueue.value = curPoint.value;
					if (addQueue.value <= subArr[nextPoint.x][nextPoint.y]) {
						subArr[nextPoint.x][nextPoint.y] = addQueue.value;
						q.push(addQueue);
					}
				}
				else {
					addQueue.value = curPoint.value + 1;
					if (addQueue.value <= subArr[nextPoint.x][nextPoint.y]) {
						subArr[nextPoint.x][nextPoint.y] = addQueue.value;
						q.push(addQueue);
					}
				}
			}
		}
	}

	if (subArr[t.x][t.y] < 4) {
		for (int i = 0; i < n; i++) delete[] subArr[i];
		delete[] subArr;
		return true;
	}
	else {
		for (int i = 0; i < n; i++) delete[] subArr[i];
		delete[] subArr;
		return false;
	}
}

void moveSuggestion(int** Pika, int n, int m, Point enterPoint) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (Pika[i][j] != -1) {
				for (int row = 1; row <= n; row++)
					for (int col = 1; col <= m; col++)
						if (Pika[i][j] == Pika[row][col] && (i != row || j != col)) {
							Point s, t;
							s.x = i; s.y = j;
							t.x = row; t.y = col;


							if (getPathValue(s, t, Pika, n, m)) {
								renderConsole(j * 10, i * 5, Pika[i][j], 30);
								renderConsole(col * 10, row * 5, Pika[row][col], 30);
								Sleep(300);
								if (enterPoint.x != i || enterPoint.y != j) renderConsole(j * 10, i * 5, Pika[i][j], 7);
								else renderConsole(j * 10, i * 5, Pika[i][j], 59);
								if (enterPoint.x != row || enterPoint.y != col) renderConsole(col * 10, row * 5, Pika[row][col], 7);
								else renderConsole(col * 10, row * 5, Pika[row][col], 59);
								return;
							}
						}
			}
}

bool checkEndGame(int** Pika, int n, int m) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (Pika[i][j] != -1) return false;

	system("cls");
	return true;
}

bool checkNotPath(int** Pika, int n, int m) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (Pika[i][j] != -1) {
				for (int row = 1; row <= n; row++)
					for (int col = 1; col <= m; col++)
						if (Pika[i][j] == Pika[row][col] && (i != row || j != col)) {
							Point s, t;
							s.x = i; s.y = j;
							t.x = row; t.y = col;

							if (getPathValue(s, t, Pika, n, m)) return false;
						}
			}

	return true;
}

void randomGame(int** Pika, int n, int m) {
	QueueInt q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (Pika[i][j] != -1) {
				q.push(Pika[i][j]);
				Pika[i][j] = -1;
			}

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		int row, col;
		do {
			row = rand() % n + 1;
			col = rand() % m + 1;
		} while (Pika[row][col] != -1);
		Pika[row][col] = k;
	}
}