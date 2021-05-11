#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
typedef pair<int, int>P;
int n, l, r;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int visited[51][51];
vector<vector<int>>arr;
queue<P>q, qq;

void bfs() {
	int sum = 0, cnt = 1;
	while (!q.empty()) {
		P now = q.front();
		q.pop();
		int x = now.first;
		int y = now.second;
		sum += arr[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (visited[nx][ny] == 1)
				continue;
			if (abs(arr[nx][ny] - arr[x][y]) >= l && abs(arr[nx][ny] - arr[x][y]) <= r) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
				qq.push({ nx,ny });
				cnt++;
			}
		}
	}
	while (!qq.empty()) {
		int x = qq.front().first;
		int y = qq.front().second;
		qq.pop();
		arr[x][y] = sum / cnt;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l >> r;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x; cin >> x;
			arr[i].push_back(x);
		}
	}
	int res = 0;
	while (true) {
		for (int i = 0; i < n; i++) {
			fill(visited[i], visited[i] + n, -1);
		}
		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == -1) {
					visited[i][j] = 1;
					q.push({ i,j });
					qq.push({ i,j });
					bfs();
					num++;
				}
			}
		}
		if (num == n * n)
			break;
		res++;
	}
	cout << res;
	return 0;
}