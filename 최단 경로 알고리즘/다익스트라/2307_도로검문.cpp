#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
typedef long long ll;
vector<P>arr[1001];
int dist[1001];
int path[1001];
int n, m, res = 0;
priority_queue<P, vector<P>, greater<P>>pq;

ll dijkstra(int x, int y) {
	fill(dist, dist + 1001, INF);
	dist[1] = 0;
	pq.push(P(0, 1));
	while (!pq.empty()) {
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int nd = arr[now][i].second;
			if ((now == x && next == y) || (now == y && next == x))
				continue;
			if (dist[next] > dist[now] + nd) {
				dist[next] = dist[now] + nd;
				pq.push(P(dist[next], next));
				if (x == 0 && y == 0)
					path[next] = now;
			}
		}
	}
	return dist[n];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		arr[a].push_back(P(b, t));
		arr[b].push_back(P(a, t));
	}
	fill(path, path + 1001, -1);
	dijkstra(0, 0);
	int time = dist[n];
	for (int i = n; path[i] != -1; i = path[i]) {
		int block = dijkstra(i, path[i]);
		if (block >= INF) {
			printf("-1");
			return 0;
		}
		res = max(res, block - time);
	}
	printf("%d", res);
	return 0;
}
