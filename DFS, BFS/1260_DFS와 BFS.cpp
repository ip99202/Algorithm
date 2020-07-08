#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int>arr[1001];
queue<int>q;
bool visited[1001];

void dfs(int now) {
	visited[now] = true;
	printf("%d ", now);
	for (int i = 0; i < arr[now].size(); i++) {
		int next = arr[now][i];
		if (visited[next] == true)
			continue;
		dfs(next);
	}
}

void bfs(int st) {
	visited[st] = true;
	q.push(st);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d ", now);
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			if (visited[next] == false) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m, v;
	scanf("%d%d%d", &n, &m, &v);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		sort(arr[i].begin(), arr[i].end());
	dfs(v);
	printf("\n");
	memset(visited, false, sizeof(visited));
	bfs(v);
	return 0;
}