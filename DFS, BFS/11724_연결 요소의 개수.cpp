#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int, int>P;
vector<vector<int>>v;
bool visited[1001];
int cnt;

void dfs(int now) {
	visited[now] = true;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (visited[next] == true)
			continue;
		dfs(next);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d", cnt);
}