#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int parent[100001];
vector<int>arr(1);

int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	arr[y] += arr[x];
	arr[x] = 0;
	parent[x] = y;
}

void battle(int x, int y) {
	x = find(x);
	y = find(y);
	if (arr[x] > arr[y])
		swap(x, y);
	arr[y] -= arr[x];
	arr[x] = 0;
	parent[x] = y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i < 100001; i++)
		parent[i] = i;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		arr.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 2)
			battle(b, c);
		else
			merge(b, c);
	}
	vector<int>res;
	for (int i = 1; i <= n; i++) {
		if (arr[find(i)] == 0 || i != parent[i]) continue;
		res.push_back(arr[find(i)]);
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}