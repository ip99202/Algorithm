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
priority_queue<P, vector<P>, greater<P>>pq;
vector<vector<int>>arr;
int indegree[501], res[501], time[501];
queue<int>q;

int main() {
	int n;
	scanf("%d", &n);
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		time[i] = t;
		while (true) {
			int x;
			scanf("%d", &x);
			if (x == -1) break;
			arr[x].push_back(i);
			indegree[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			res[i] = time[i];
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			indegree[next]--;
			if (res[next] < res[now] + time[next])
				res[next] = res[now] + time[next];
			if (indegree[next] == 0)
				q.push(next);
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", res[i]);
	}
}