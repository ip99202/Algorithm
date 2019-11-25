#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
typedef long long ll;
vector<P>arr[20001];
int dist[20001];
priority_queue<P, vector<P>, greater<P>>pq;

ll dijkstra(int st, int end) {
	fill(dist, dist + 20001, INF);
	dist[st] = 0;
	pq.push(P(0, st));
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
	return dist[end];
}

int main() {
	int n, e;
	scanf("%d%d", &n, &e);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		arr[u].push_back(P(v, w));
		arr[v].push_back(P(u, w));
	}
	int n1, n2;
	scanf("%d%d", &n1, &n2);

	ll res1 = dijkstra(1, n1) + dijkstra(n1, n2) + dijkstra(n2, n);
	ll res2 = dijkstra(1, n2) + dijkstra(n2, n1) + dijkstra(n1, n);

	if (min(res1, res2) > INF)
		printf("-1");
	else
		printf("%d", min(res1, res2));
	return 0;
}
