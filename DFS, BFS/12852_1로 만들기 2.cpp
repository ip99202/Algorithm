#include<iostream>
#include<queue>
#include<stack>
using namespace std;
queue<pair<int, int>>q;
stack<int>res;
int visited[10000000];
int n;
int now, cnt;
int pre[10000000];

void num(int k) {
	res.push(pre[k]);
	if (pre[k] == n)
		return;
	num(pre[k]);
}

void bfs(int st) {
	visited[st] = 1;
	q.push(make_pair(st, cnt));
	while (!q.empty()) {
		now = q.front().first;
		cnt = q.front().second;
		if (now == 1) {
			printf("%d\n", cnt);
			num(1);
			while (!res.empty()) {
				printf("%d ", res.top());
				res.pop();
			}
			printf("1");
			return;
		}
		q.pop();
		if (now % 3 == 0) {
			int next = now / 3;
			if (next >= 0 && next <= 1000000) {
				if (visited[next] == 0) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = 1;
					pre[next] = now;
				}
			}
		}
		if (now % 2 == 0) {
			int next = now / 2;
			if (next >= 0 && next <= 1000000) {
				if (visited[next] == 0) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = 1;
					pre[next] = now;
				}
			}
		}
		int next = now - 1;
		if (next <= 1000000) {
			if (visited[next] == 0) {
				q.push(make_pair(next, cnt + 1));
				visited[next] = 1;
				pre[next] = now;
			}
		}

	}
}

int main() {
	cin >> n;
	bfs(n);
}