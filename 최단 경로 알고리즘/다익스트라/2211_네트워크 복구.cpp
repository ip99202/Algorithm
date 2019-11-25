#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>	
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
int n, m;
vector<P>arr[1001];
int dist[1001], pre[1001];
priority_queue<P, vector<P>, greater<P>>pq;

void dijkstra() {
	dist[1] = 0;
	pre[1] = 1;
	pq.push(P(0, 1));
	while (!pq.empty()) {
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int nd = arr[now][i].second;
			if (dist[next] > dist[now] + nd) {
				dist[next] = dist[now] + nd;
				pq.push(P(dist[next], next));
				pre[next] = now;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		arr[a].push_back(P(b, c));
		arr[b].push_back(P(a, c));
	}
	fill(dist, dist + 1001, INF);
	fill(pre, pre + 1001, -1);
	dijkstra();
	printf("%d\n", n - 1);
	for (int i = 2; i <= n; i++)
		printf("%d %d\n", i, pre[i]);
}