#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;
typedef long long ll;
vector<vector<int>>arr;
int cost[101], discover[101], scc[101], cnt;
stack<int>st;
ll res;

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
		int tmp = INT_MAX;
		while (true) {
			int here = st.top();
			st.pop();
			scc[here] = 1;
			tmp = min(tmp, cost[here]);
			if (here == now)
				break;
		}
		res += tmp;
	}
	return parent;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int c; cin >> c;
		cost[i] = c;
	}
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1')
				arr[i].push_back(j + 1);
		}
	}
	fill(discover, discover + 101, -1);
	fill(scc, scc + 101, -1);
	for (int i = 1; i <= n; i++) {
		if (discover[i] == -1)
			dfs(i);
	}
	cout << res;
	return 0;
}