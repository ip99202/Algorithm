#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, s, d, res;
vector<vector<int>>arr;
int cnt[100001], visited[100001];

void go(int now) {
	for (int i = 0; i < arr[now].size(); i++) {
		int next = arr[now][i];
		if (cnt[next] >= d && !visited[next]) {
			res++;
			visited[next] = 1;
			go(next);
		}
	}
}

int dfs(int now) {
	int dep = 0;
	for (int i = 0; i < arr[now].size(); i++) {
		int next = arr[now][i];
		if (visited[next]) continue;
		visited[next] = 1;
		dep = dfs(next);
		cnt[now] = max(cnt[now], dep);
	}
	return max(cnt[now], dep) + 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s >> d;
	arr.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	visited[s] = 1;
	dfs(s);
	fill(visited, visited + 100001, 0);
	visited[s] = 1;
	go(s);
	cout << (res + 1) * 2 - 2;
	return 0;
}