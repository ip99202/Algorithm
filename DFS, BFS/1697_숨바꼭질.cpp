#include<iostream>
#include<queue>
using namespace std;
queue<pair<int, int>>q;
int visited[100001];
int n, k;
int now, cnt;
int way[3] = { -1,1,2, };

void bfs(int st, int fin) {
	visited[st] = 1;
	q.push(make_pair(st, cnt));
	while (!q.empty()) {
		now = q.front().first;
		cnt = q.front().second;
		if (now == k) {
			printf("%d", cnt);
			return;
		}
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (i != 2) {
				int next = now + way[i];
				if (next >= 0 && next <= 100000) {
					if (visited[next] == 0) {
						q.push(make_pair(next, cnt + 1));
						visited[next] = 1;
					}
				}
			}
			else {
				int next = now * 2;
				if (next <= 100000) {
					if (visited[next] == 0) {
						q.push(make_pair(next, cnt + 1));
						visited[next] = 1;
					}
				}
			}
		}
	}
}

int main() {
	cin >> n >> k;
	bfs(n, k);
}