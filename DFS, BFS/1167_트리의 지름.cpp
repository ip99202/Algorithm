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
vector<vector<P>>arr;
queue<P>q;
bool visited[100001];
int res;
P node;

void bfs() {
	while (!q.empty()) {
		int now = q.front().first;
		int len = q.front().second;
		q.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int nlen = arr[now][i].second;
			if (visited[next] == true)
				continue;
			nlen += len;
			visited[next] = true;
			q.push(P(next, nlen));
			if (res < nlen) {
				res = nlen;
				node = P(next, nlen);
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int k, x, y;
		scanf("%d", &k);
		while (true) {
			scanf("%d", &x);
			if (x == -1) break;
			scanf("%d", &y);
			arr[k].push_back(P(x, y));
		}
	}
	visited[1] = true;
	q.push(P(1, 0));
	bfs();
	fill(visited, visited + 100001, false);
	q.push(P(node.first, 0));
	res = 0;
	visited[node.first] = true;
	node = P(0, 0);
	bfs();
	printf("%d", node.second);
}