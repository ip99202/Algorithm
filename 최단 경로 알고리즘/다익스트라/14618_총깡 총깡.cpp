#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 999999999
using namespace std;
typedef pair<int, int>P;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, j, k;
	cin >> n >> m >> j >> k;
	vector<vector<P>>arr(n + 1);
	vector<int>A, B;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < k; i++) {
		int b;
		cin >> b;
		B.push_back(b);
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		arr[x].push_back(P(y, z));
		arr[y].push_back(P(x, z));
	}
	vector<int>dist(n + 1, INF);
	priority_queue<P, vector<P>, greater<P>>pq;
	dist[j] = 0;
	pq.push(P(0, j));
	while (!pq.empty()) {
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int nd = arr[now][i].second;
			if (dist[next] > dist[now] + nd) {
				dist[next] = dist[now] + nd;
				pq.push(P(dist[next], next));
			}
		}
	}
	int acost = INF, bcost = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			if (i == A[j])
				acost = min(acost, dist[A[j]]);
		}
		for (int j = 0; j < k; j++) {
			if (i == B[j])
				bcost = min(bcost, dist[B[j]]);
		}
	}
	if (acost == INF && bcost == INF) {
		cout << -1;
		return 0;
	}
	if (acost <= bcost)
		cout << 'A' << "\n" << acost;
	else
		cout << 'B' << "\n" << bcost;
	return 0;
}