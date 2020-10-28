#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<stack>
#include<algorithm>
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
typedef long long ll;
vector<P>arr[1001];
int dist[1001];
int path[1001];
stack<int>way;
int n, m, res = 0;
priority_queue<P, vector<P>, greater<P>>pq;

ll dijkstra(int x, int y) {
	fill(dist, dist + 1001, INF);
	dist[x] = 0;
	pq.push(P(0, x));
	while (!pq.empty()) {
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int nd = arr[now][i].second;
			if (dist[next] > dist[now] + nd) {
				dist[next] = dist[now] + nd;
				pq.push(P(dist[next], next));
				path[next] = now;
			}
		}
	}
	return dist[y];
}

void back(int end) {
	if (path[end] == -1)
		return;
	way.push(end);
	back(path[end]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		arr[a].push_back(P(b, t));
	}
	int st, end;
	scanf("%d%d", &st, &end);
	fill(path, path + 1001, -1);
	printf("%d\n", dijkstra(st, end));
	back(end);
	int len = way.size();
	printf("%d\n", len + 1);
	printf("%d ", st);
	for (int i = 0; i < len; i++) {
		printf("%d ", way.top());
		way.pop();
	}
	return 0;
}
