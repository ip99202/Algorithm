#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 999999999
using namespace std;
int arr[1001][1001];
int dist[1001];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			arr[i][j] = INF;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (arr[a][b] > c)
			arr[a][b] = c;
	}
	int st, end;
	scanf("%d%d", &st, &end);
	fill(dist, dist + 1001, INF);
	dist[st] = 0;
	bool flag;
	for (int i = 1; i < n; i++) {
		flag = false;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dist[j] != INF && dist[k] > dist[j] + arr[j][k]) {
					dist[k] = dist[j] + arr[j][k];
					flag = true;
				}
			}
		}
		if (!flag)
			break;
	}
	printf("%d", dist[end]);
	return 0;
}#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX_V = 20000;
const int INF = 1000000000;
typedef pair<int, int>P;
vector<P>adj[MAX_V];
bool visited[MAX_V];
int dist[MAX_V];
priority_queue<P, vector<P>, greater<P>>PQ;
vector<int>res;

long long di(int st, int end) {
	fill(dist, dist + MAX_V, INF);
	dist[st] = 0;
	PQ.push(P(0, st));
	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);
		if (visited[curr])
			break;
		visited[curr] = true;
		for (int i = 0; i < adj[curr].size(); i++) {
			int next = adj[curr][i].first, d = adj[curr][i].second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}
	memset(visited, false, MAX_V);
	return dist[end];
}

int main() {
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(P(v, w));
	}

	for (int i = 1; i <= n; i++)
		res.push_back(di(i, x) + di(x, i));
	sort(res.begin(), res.end());

	printf("%d", res[n - 1]);
}