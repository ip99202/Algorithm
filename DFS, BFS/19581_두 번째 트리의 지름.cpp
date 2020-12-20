#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>P;
typedef long long ll;
vector<vector<P>>arr;
vector<int>visited;
ll res, node;

void dfs(int now, ll sum) {
	visited[now] = 1;
	for (int i = 0; i < arr[now].size(); i++) {
		int next = arr[now][i].first;
		int cost = arr[now][i].second;
		if (visited[next]) continue;
		if (res < sum + cost) {
			res = sum + cost;
			node = next;
		}
		dfs(next, sum + cost);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	arr.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	dfs(1, 0);
	int n1 = node;
	res = 0;
	fill(visited.begin(), visited.end(), 0);
	dfs(n1, 0);
	int n2 = node;

	ll maxx = 0;
	res = 0;
	fill(visited.begin(), visited.end(), 0);
	visited[n1] = 1;
	dfs(n2, 0);
	maxx = max(maxx, res);

	res = 0;
	fill(visited.begin(), visited.end(), 0);
	visited[n2] = 1;
	dfs(n1, 0);
	maxx = max(maxx, res);

	cout << maxx;
	return 0;
}