#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>	
#define INF 999999999
using namespace std;
typedef pair<int, long long>P;
queue<int>q;
long long dist[101];
bool visited[101];
vector<vector<P>>trans;
vector<int>income;

void bfs() {
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < trans[now].size(); i++) {
			int next = trans[now][i].first;
			if (visited[next] == false) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m, st, end;
	scanf("%d %d %d %d", &n, &st, &end, &m);
	trans.resize(n);

	for (int i = 0; i < m; i++) {
		int s, e;
		long long c;
		scanf("%d %d %lld", &s, &e, &c);
		trans[s].push_back(P(e, c));
	}
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		income.push_back(x);
	}
	q.push(st);
	visited[st] = true;
	bfs();
	if (visited[end] == false) {
		printf("gg");
		return 0;
	}
	fill(visited, visited + 101, false);
	fill(dist, dist + 101, INF);
	dist[st] = -income[st];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[j] != INF) {
				int len = trans[j].size();
				for (int k = 0; k < len; k++) {
					int to = trans[j][k].first;
					long long cost = trans[j][k].second - income[to];
					if (dist[to] > dist[j] + cost) {
						dist[to] = dist[j] + cost;
						if (i == n - 1) {
							q.push(j);
							visited[j] = true;
						}
					}
				}
			}
		}
	}
	bfs();
	if (visited[end])
		printf("Gee");
	else
		printf("%lld", -dist[end]);
}