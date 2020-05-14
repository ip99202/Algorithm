#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<int>arr[1001];
int visited[1001];
bool match[1001];
int n, m, cnt;

bool dfs(int x) {
	if (match[x]) return false;
	match[x] = 1;
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
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		arr[x].push_back(y);

	}
	for (int i = 1; i <= n; i++) {
		fill(match, match + 1001, false);
		if (dfs(i))
			cnt++;
	}
	printf("%d", cnt);
}