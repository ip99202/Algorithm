#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
int v, e, k;
vector<P>arr[20005];
int dist[20005];
bool visited[20005];
priority_queue<P, vector<P>, greater<P>>pq;

void dijkstra(int st) {
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
}

int main() {
	scanf("%d%d%d", &v, &e, &k);
	k--;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		arr[u - 1].push_back(P(v - 1, w));
	}
	fill(dist, dist + 20005, INF);
	dijkstra(k);
	for (int i = 0; i < v; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
}