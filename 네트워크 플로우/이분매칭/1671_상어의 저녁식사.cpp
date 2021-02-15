#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<int>arr[51];
int shark[51][3];
int visited[51];
bool match[51];
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
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		shark[i][0] = a;
		shark[i][1] = b;
		shark[i][2] = c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (shark[i][0] >= shark[j][0] && shark[i][1] >= shark[j][1] && shark[i][2] >= shark[j][2])
				arr[i].push_back(j);
			else if (shark[j][0] >= shark[i][0] && shark[j][1] >= shark[i][1] && shark[j][2] >= shark[i][2])
				arr[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		fill(match, match + 51, false);
		if (dfs(i))
			cnt++;
	}
	for (int i = 1; i <= n; i++) {
		fill(match, match + 51, false);
		if (dfs(i))
			cnt++;
	}
	printf("%d", n - cnt);
}