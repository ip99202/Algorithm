#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
vector<vector<int>>path;
queue<int>q;
bool visited[20001];
int cnt[20001];
int res_1 = 100000, res_2, res_3;

void bfs() {
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < path[now].size(); i++) {
			int next = path[now][i];
			if (visited[next] == false) {
				q.push(next);
				visited[next] = true;
				cnt[next] = cnt[now] + 1;
				res_2 = max(res_2, cnt[next]);
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	path.resize(n + 1);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		path[a].push_back(b);
		path[b].push_back(a);
	}
	bfs();
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == res_2) {
			res_1 = min(res_1, i);
			res_3++;
		}
	}
	printf("%d %d %d", res_1, res_2, res_3);
}