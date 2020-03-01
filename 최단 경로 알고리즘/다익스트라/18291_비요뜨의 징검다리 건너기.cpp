#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>	
#define INF 1e18
using namespace std;
typedef long long ll;
typedef pair<int, int>P;
vector<P>arr[100001];
ll dist[100001];
priority_queue<P, vector<P>, greater<P>>pq;

void dijkstra(int st) {
	while (!pq.empty()) {
		int now = pq.top().second;
		int di = pq.top().first;
		pq.pop();
		if (dist[now] < di) continue;
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int nd = arr[now][i].second;
			if (dist[next] > dist[now] + nd) {
				dist[next] = dist[now] + nd;
				pq.push(P(dist[next], next));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	fill(dist, dist + 100001, INF);
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		arr[v].push_back(P(u, c));
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		arr[0].push_back(P(x, 0));
	}
	pq.push(P(0, 0));
	dist[0] = 0;
	dijkstra(0);
	ll res = 0, node = 0;
	for (int i = 0; i < 100001; i++) {
		if (dist[i] == INF) continue;
		if (res < dist[i]) {
			res = dist[i];
			node = i;
		}
	}
	cout << node << "\n" << res;
	return 0;
}