#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>P;
int dx[] = { 0,0,1,1,1,-1,-1,-1 };
int dy[] = { 1,-1,1,0,-1,1,0,-1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int r, s; cin >> r >> s;
	vector<vector<char>>arr(r);
	vector<vector<int>>visited(r);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			char x; cin >> x;
			arr[i].push_back(x);
			visited[i].push_back(0);
		}
	}
	vector<vector<int>>cnt = visited;
	int maxx = 0, res = 0;
	P pl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			if (arr[i][j] == '.') continue;
			for (int k = 0; k < 8; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= r || ny < 0 || ny >= s)
					continue;
				if (visited[nx][ny] == 0 && arr[nx][ny] == 'o')
					res++;
				if (arr[nx][ny] == '.')
					cnt[nx][ny]++;
				if (maxx < cnt[nx][ny]) {
					maxx = cnt[nx][ny];
					pl.first = nx;
					pl.second = ny;
				}
			}
			visited[i][j] = 1;
		}
	}
	cout << res + maxx;
	return 0;
}