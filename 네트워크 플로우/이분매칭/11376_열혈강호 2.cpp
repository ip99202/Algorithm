#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<int>arr[1001];
int visited[1001];
int match[1001];
int n, m, cnt;

bool dfs(int x) {
	if (match[x] == 2) return false;
	match[x]++;
	for (int i = 0; i < arr[x].size(); i++) {
		int temp = arr[x][i];
		if (!visited[temp] || dfs(visited[temp])) {
			visited[temp] = x;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		for (int j = 0; j < x; j++) {
			int y;
			scanf("%d", &y);
			arr[i].push_back(y);
		}
	}
	for (int i = 1; i <= n; i++) {
		fill(match, match + 1001, 0);
		if (dfs(i))
			cnt++;
		if (dfs(i))
			cnt++;
	}
	printf("%d", cnt);
}