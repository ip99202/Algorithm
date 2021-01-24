#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 99999999
using namespace std;
typedef pair<int, int>P;
vector<P>arr;
vector<int>v[100001];
int visited[100001];
queue<int>q;
vector<int>res;
int max_x = 0, max_y = 0, min_x = MAX, min_y = MAX;

void bfs(int st) {
	while (!q.empty()) {
		int now = q.front();
		int x = arr[now].first;
		int y = arr[now].second;
		q.pop();
		max_x = max(max_x, x);
		max_y = max(max_y, y);
		min_x = min(min_x, x);
		min_y = min(min_y, y);
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (visited[next] == 0) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	arr.push_back(P(0, 0));
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr.push_back(P(a, b));
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		max_x = 0, max_y = 0, min_x = MAX, min_y = MAX;
		if (visited[i] == 0) {
			q.push(i);
			bfs(i);
			int x = max_x - min_x;
			int y = max_y - min_y;
			res.push_back((x + y) * 2);
		}
	}
	sort(res.begin(), res.end());
	printf("%d", res[0]);
}