#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<deque>
#include<queue>
#include<cstring>
using namespace std;
vector<vector<int>>v;
int visited[105];
queue<int>q;

bool bfs(int x, int y) {
	q.push(x);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (visited[next] == 0) {
				visited[next] = visited[now] + 1;
				q.push(next);
				if (next == y)
					return true;
			}
		}
	}

}

int main() {
	int n, x, y, m;
	scanf("%d", &n);
	v.resize(n + 1);
	scanf("%d%d%d", &x, &y, &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[x]++;
	if (bfs(x, y))
		printf("%d", visited[y] - 1);
	else
		printf("-1");
}