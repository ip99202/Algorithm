#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 100001
using namespace std;
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
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr.push({ a,b,c });
	}
	for (int i = 0; i < MAX; i++)
		parent[i] = i;

	int sum = 0;
	while (!arr.empty()) {
		if (!isUnion(arr.top().st, arr.top().end)) {
			sum += arr.top().distance;
			merge(arr.top().st, arr.top().end);
		}
		arr.pop();
	}
	cout << sum;
	return 0;
}