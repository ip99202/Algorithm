#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#define INF 1000000000
using namespace std;
typedef pair<int, int>P;
int dist[1001], path[1001];
priority_queue<P, vector<P>, less<P>>pq;
stack<int>res;

void printPath(int st) {
	res.push(st);
	if (path[st] == 1) {
		res.push(1);
		return;
	}
	printPath(path[st]);

}

void dijkstra(int st, vector<vector<P>>& arr) {
	pq.push({ 0,st });
	while (!pq.empty()) {
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int nd = arr[now][i].second;
			if (dist[next] < dist[now] + nd) {
				dist[next] = dist[now] + nd;
				path[next] = now;
				if (next == 1) continue;
				pq.push({ dist[next],next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<vector<P>>arr(n + 1);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		arr[a].push_back({ b,c });
	}
	dijkstra(1, arr);
	cout << dist[1] << "\n";
	printPath(1);
	while (!res.empty()) {
		cout << res.top() << " ";
		res.pop();
	}
	return 0;
}