#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
int arr[201][201], visited[201][201];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m, s, x, y;
struct virus {
	int num, x, y, time;
};
deque<virus>q;
bool cmp(virus a, virus b) {
	return a.num < b.num;
}

void bfs() {
	while (!q.empty()) {
		virus now = q.front();
		int xx = now.x;
		int yy = now.y;
		int nn = now.num;
		int ntime = now.time;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > n)
				continue;
			if (arr[nx][ny] != 0 || s < ntime + 1)
				continue;
			arr[nx][ny] = nn;
			q.push_back({ nn,nx,ny,ntime + 1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0)
				q.push_back({ arr[i][j],i,j,0 });
		}
	}
	sort(q.begin(), q.end(), cmp);
	cin >> s >> x >> y;
	bfs();
	cout << arr[x][y];
	return 0;
}