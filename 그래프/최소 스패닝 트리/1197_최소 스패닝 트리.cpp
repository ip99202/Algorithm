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
priority_queue<P>pq;
vector<vector<P>>arr;
bool visited[10001];
int res;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	arr.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		arr[a].push_back(P(b, -c));
		arr[b].push_back(P(a, -c));
	}
	for (int i = 0; i < arr[1].size(); i++)
		pq.push(P(arr[1][i].second, arr[1][i].first));
	visited[1] = true;
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (visited[now] == true)
			continue;
		visited[now] = true;
		res += cost;
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int ncost = arr[now][i].second;
			if (visited[next] == true)
				continue;
			pq.push(P(ncost, next));
		}
	}
	printf("%d", -res);
}