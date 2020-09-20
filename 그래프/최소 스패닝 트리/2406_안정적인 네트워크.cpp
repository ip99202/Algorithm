#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 10001
using namespace std;
typedef pair<int, int>P;
int parent[MAX];

struct edge {
	int st, end, distance;
};
struct cmp {
	bool operator()(edge x, edge y) {
		return x.distance > y.distance;
	}
};

int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	parent[y] = x;
}

bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<edge, vector<edge>, cmp>arr;
	int n, m; cin >> n >> m;
	for (int i = 0; i < MAX; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		merge(a, b);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			if (i >= j || i == 1) continue;
			arr.push({ i,j,x });
		}
	}

	int sum = 0;
	vector<P>res;
	while (!arr.empty()) {
		if (!isUnion(arr.top().st, arr.top().end)) {
			sum += arr.top().distance;
			merge(arr.top().st, arr.top().end);
			res.push_back(P(arr.top().st, arr.top().end));
		}
		arr.pop();
	}
	if (sum == 0) {
		cout << 0 << " " << 0;
		return 0;
	}
	cout << sum << " " << res.size() << "\n";
	for (int i = 0; i < res.size(); i++)
		cout << res[i].first << " " << res[i].second << "\n";
	return 0;
}