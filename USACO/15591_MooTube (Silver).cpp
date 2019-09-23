#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<climits>
using namespace std;
typedef pair<int, long long>P;
vector<vector<P>>arr;
bool visited[5001];
long long res[5001][5001];
int ans, now;

void dfs(int n, long long cost) {
	for (int i = 0; i < arr[n].size(); i++) {
		int next = arr[n][i].first;
		if (visited[next])
			continue;
		visited[next] = true;
		long long ncost = arr[n][i].second;
		res[now][next] = min(cost, ncost);
		dfs(next, min(cost, ncost));
	}
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	arr.resize(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		long long c;
		scanf("%d%d%lld", &a, &b, &c);
		arr[a].push_back(P(b, c));
		arr[b].push_back(P(a, c));
	}
	for (int i = 1; i <= n; i++) {
		now = i;
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		dfs(i, LLONG_MAX);
	}
	for (int i = 1; i <= q; i++) {
		long long a;
		int b;
		scanf("%lld%d", &a, &b);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (i == b)
				continue;
			if (res[b][i] >= a)
				ans++;
		}
		printf("%d\n", ans);
	}
}