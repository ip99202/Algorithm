#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
vector<vector<int>>arr;
vector<vector<int>>scc_arr;
vector<int>restaurant, scc_restaurant;
int cost[500001], tcost[500001], discover[500001], scc[500001], money[500001];
int cnt, scc_cnt = 1, res, start, scc_start;
stack<int>st;
queue<int>q;

int dfs(int now) {
	st.push(now);
	discover[now] = cnt++;
	int parent = discover[now];
	for (int i = 0; i < arr[now].size(); i++) {
		int next = arr[now][i];
		if (discover[next] == -1)
			parent = min(parent, dfs(next));
		else if (scc[next] == -1)
			parent = min(parent, discover[next]);
	}
	if (parent == discover[now]) {
		while (true) {
			int here = st.top();
			st.pop();
			scc[here] = scc_cnt;
			tcost[scc_cnt] += cost[here];
			if (restaurant[here])
				scc_restaurant[scc_cnt] = 1;
			if (start == here)
				scc_start = scc_cnt;
			if (here == now)
				break;
		}
		scc_cnt++;
	}
	return parent;
}

void bfs() {
	money[q.front()] = tcost[q.front()];
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (scc_restaurant[now])
			res = max(res, money[now]);
		for (int i = 0; i < scc_arr[now].size(); i++) {
			int next = scc_arr[now][i];
			if (money[next] < money[now] + tcost[next]) {
				money[next] = money[now] + tcost[next];
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	arr.resize(n + 1);
	scc_arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		arr[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		cost[i] = x;
	}
	int p; cin >> start >> p;
	restaurant.resize(n + 1);
	scc_restaurant.resize(n + 1);
	for (int i = 0; i < p; i++) {
		int x; cin >> x;
		restaurant[x] = 1;
	}
	fill(discover, discover + 500001, -1);
	fill(scc, scc + 500001, -1);
	for (int i = 1; i <= n; i++) {
		if (discover[i] == -1)
			dfs(i);
	}
	for (int now = 1; now <= n; now++) {
		for (int i = 0; i < arr[now].size(); i++) {
			if (scc[now] != scc[arr[now][i]])
				scc_arr[scc[now]].push_back(scc[arr[now][i]]);
		}
	}
	q.push(scc_start);
	bfs();
	cout << res;
	return 0;
}