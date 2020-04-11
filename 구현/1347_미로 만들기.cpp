#include<iostream>
#include<algorithm>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char map[100][100];
char arr[51];
int n;

char direction(int i, char way) {
	if (arr[i] == 'L' && way == 'n')
		return 'e';
	else if (arr[i] == 'L' && way == 'w')
		return 'n';
	else if (arr[i] == 'L' && way == 's')
		return 'w';
	else if (arr[i] == 'L' && way == 'e')
		return 's';
	else if (arr[i] == 'R' && way == 'n')
		return 'w';
	else if (arr[i] == 'R' && way == 'w')
		return 's';
	else if (arr[i] == 'R' && way == 's')
		return 'e';
	else if (arr[i] == 'R' && way == 'e')
		return 'n';
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	char way = 'n';
	int x = 50, y = 50;
	map[x][y] = '.';
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'R' || arr[i] == 'L')
			way = direction(i, way);
		else if (arr[i] == 'F') {
			int go;
			if (way == 'e')	go = 0;
			else if (way == 'w') go = 1;
			else if (way == 'n') go = 2;
			else if (way == 's') go = 3;
			x = x + dx[go];
			y = y + dy[go];
			map[y][x] = '.';
		}
	}

	int sx = 100, sy = 100, ex = 0, ey = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] == '.') {
				if (i < sx) sx = i;
				if (j < sy) sy = j;
				if (i > ex) ex = i;
				if (j > ey) ey = j;
			}

	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			if (map[i][j] == '.')
				cout << ".";
			else cout << "#";
		}
		cout << endl;
	}

}