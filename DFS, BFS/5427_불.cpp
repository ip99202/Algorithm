#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int, int>P;
int visited[1000][1000];
char arr[1000][1000];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int w, h;
queue<P>q, fire;

int bfs() {
	while (!q.empty()) {
		int fsize = fire.size();
		for (int i = 0; i < fsize; i++) {
			P nowfire = fire.front();
			fire.pop();
			for (int i = 0; i < 4; i++) {
				P nextfire = P(nowfire.first + dx[i], nowfire.second + dy[i]);
				if (arr[nextfire.first][nextfire.second] == '.' &&
					nextfire.first < h && nextfire.first >= 0 &&
					nextfire.second < w && nextfire.second >= 0) {
					arr[nextfire.first][nextfire.second] = '*';
					fire.push(P(nextfire.first, nextfire.second));
				}
			}
		}
		int psize = q.size();
		for (int i = 0; i < psize; i++) {
			P now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				P next = P(now.first + dx[i], now.second + dy[i]);
				if (next.first >= h || next.first < 0 || next.second >= w || next.second < 0) {
					return visited[now.first][now.second];
				}
				if (arr[next.first][next.second] == '#')
					continue;
				if (visited[next.first][next.second] > 0)
					continue;
				if (arr[next.first][next.second] == '.') {
					arr[next.first][next.second] = '@';
					q.push(P(next.first, next.second));
					visited[next.first][next.second] = visited[now.first][now.second] + 1;
				}
			}
		}
	}
	return -1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(visited, 0, sizeof(visited));
		memset(arr, 0, sizeof(arr));

		scanf("%d%d", &w, &h);
		for (int i = 0; i < h; i++) {
			getchar();
			for (int j = 0; j < w; j++) {
				char temp;
				scanf("%c", &temp);
				arr[i][j] = temp;
				if (temp == '@')
					q.push(P(i, j));
				if (temp == '*')
					fire.push(P(i, j));
			}
		}
		visited[q.front().first][q.front().second]++;
		int res = bfs();
		if (res == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", res);
		while (!q.empty()) q.pop();
		while (!fire.empty()) fire.pop();
	}
}