#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<int>arr[1001];
int visited[1001];
bool match[1001];
int n, m, k, cnt;

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
	scanf("%d%d%d", &n, &m, &k);
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
	}
	for (int i = 1; i <= n && k > 0; i++) {
		fill(match, match + 1001, 0);
		if (dfs(i)) {
			cnt++;
			k--;
		}
	}
	printf("%d", cnt);
}