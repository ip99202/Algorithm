#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 1000000000
using namespace std;
int parent[1001];

struct edge {
	int st, end, cost;
};
bool operator<(edge x, edge y) {
	return x.cost > y.cost;
}
priority_queue<edge, vector<edge>>arr;

int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
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
	int n, m, k; cin >> n >> m >> k;
	vector<int>tmp;
	for (int i = 0; i < 1001; i++)
		parent[i] = i;
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		tmp.push_back(x);
	}
	for (int i = 1; i < k; i++)
		merge(tmp[i - 1], tmp[i]);

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr.push({ a,b,c });
	}
	int sum = 0;
	while (!arr.empty()) {
		if (!isUnion(arr.top().st, arr.top().end)) {
			sum += arr.top().cost;
			merge(arr.top().st, arr.top().end);
		}
		arr.pop();
	}
	cout << sum;
	return 0;
}