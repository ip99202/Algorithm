#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>P;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char arr[6][6];
vector<P>stu, tea, obj, able;
int n, find_flag;
bool res_flag = false;

void search(P now) {
	for (int i = 0; i < 4; i++) {
		int nx = now.first + dx[i];
		int ny = now.second + dy[i];
		while (true) {
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				break;
			if (arr[nx][ny] == 'S') {
				find_flag++;
				return;
			}
			else if (arr[nx][ny] == 'O')
				break;
			nx += dx[i];
			ny += dy[i];
		}
	}
}

void observe() {
	find_flag = 0;
	for (int i = 0; i < tea.size(); i++) {
		search(tea[i]);
	}
	if (find_flag == 0) {
		cout << "YES";
		res_flag = true;
	}
}

void install(int cnt, int x, int y) {
	if (res_flag) return;
	if (cnt == 3) {
		observe();
		return;
	}
	bool flag = false;
	for (int i = x; i < n; i++) {
		int j = y;
		if (i > x)
			flag = true;
		if (flag) j = 0;
		for (j; j < n; j++) {
			if (arr[i][j] == 'X') {
				arr[i][j] = 'O';
				install(cnt + 1, i, j);
				arr[i][j] = 'X';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char x; cin >> x;
			arr[i][j] = x;
			if (x == 'S')
				stu.push_back({ i,j });
			else if (x == 'T')
				tea.push_back({ i,j });
			else if (x == 'O')
				obj.push_back({ i,j });
			else
				able.push_back({ i,j });
		}
	}
	install(0, 0, 0);
	if (!res_flag)
		cout << "NO";
	return 0;
}
//https://www.acmicpc.net/problem/18428