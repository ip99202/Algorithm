#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 999999999
using namespace std;
typedef pair<int, int>P;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, t, res = 0;
	cin >> n >> m >> t;
	vector<vector<P>>arr(n + 1);
	bool visited[10001] = { false };
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back(P(b, c));
		arr[b].push_back(P(a, c));
	}
	priority_queue<P, vector<P>, greater<P>>pq;
	visited[1] = true;
	int cnt = 0;
	for (int i = 0; i < arr[1].size(); i++)
		pq.push(P(arr[1][i].second, arr[1][i].first));
	while (!pq.empty()) {
		int ncost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (visited[now]) continue;
		visited[now] = true;
		res += (ncost + cnt * t);
		for (int i = 0; i < arr[now].size(); i++)
			pq.push(P(arr[now][i].second, arr[now][i].first));
		cnt++;
	}
	cout << res;
	return 0;
}