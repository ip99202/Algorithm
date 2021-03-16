#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int>indegree;
vector<int>time;
vector<vector<int>>v;
vector<int>work;
int n;

void bfs() {
	queue<int>q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) {
			q.push(i);
			time[i] = work[i];
		}
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i];
			indegree[next]--;
			if (time[next] < time[here] + work[next])
				time[next] = time[here] + work[next];
			if (indegree[next] == 0)
				q.push(next);
		}
	}
}

int main() {
	cin >> n;
	v.resize(n + 1);
	time.resize(n + 1);
	work.resize(n + 1);
	indegree.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> work[i];
		cin >> k;
		for (int j = 0; j < k; j++) {
			int t;
			cin >> t;
			v[t].push_back(i);
			indegree[i]++;
		}
	}
	bfs();
	sort(time.begin(), time.end());
	cout << time[n];
}
