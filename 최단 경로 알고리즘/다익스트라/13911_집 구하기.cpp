#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
int v, e, k, res = INF;
vector<P>arr[300001];

void dijkstra(priority_queue<pair<int, int>>& pq, vector<int>& dist) {
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		int len = arr[now].size();
		pq.pop();
		for (int i = 0; i < len; i++) {
			int next = arr[now][i].first;
			int nd = arr[now][i].second;
			if (dist[next] > cost + nd) {
				dist[next] = cost + nd;
				pq.push(P(-dist[next], next));
			}
		}
	}
}

int main() {
	scanf("%d%d", &v, &e);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		arr[u].push_back(P(v, w));
		arr[v].push_back(P(u, w));
	}
	priority_queue<pair<int, int>> pq;
	vector<int>dist1(v + 1, INF);
	int m, x;
	scanf("%d%d", &m, &x);
	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		dist1[k] = 0;
		pq.push(P(0, k));
	}
	dijkstra(pq, dist1);
	vector<int>dist2(v + 1, INF);
	int s, y;
	scanf("%d%d", &s, &y);
	for (int i = 0; i < s; i++) {
		int k;
		scanf("%d", &k);
		dist2[k] = 0;
		pq.push(P(0, k));
	}
	dijkstra(pq, dist2);

	for (int i = 1; i <= v; i++) {
		if (dist1[i] != 0 && dist2[i] != 0 &&
			dist1[i] <= x && dist2[i] <= y && dist1[i] + dist2[i] < res)
			res = dist1[i] + dist2[i];
	}
	if (res == INF)
		printf("-1");
	else
		printf("%d", res);
}