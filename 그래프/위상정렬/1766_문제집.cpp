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
vector<int>indegree;
priority_queue<int, vector<int>, greater<int>>q;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	arr.resize(n + 1);
	indegree.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int now = q.top();
		q.pop();
		printf("%d ", now);
		for (int i = 0; i < arr[now].size(); i++) {
			indegree[arr[now][i]]--;
			if (indegree[arr[now][i]] == 0)
				q.push(arr[now][i]);
		}
	}
}