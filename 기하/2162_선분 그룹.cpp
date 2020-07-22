#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>P;
typedef pair<P, P>PP;
int parent[3001], sum[3001];

struct node {
	int x1, y1, x2, y2;
};

int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	sum[x] += sum[y];
	parent[y] = x;
}

bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	return false;
}

int ccw(P a, P b, P c) {
	int res = a.first * b.second + b.first * c.second + c.first * a.second;
	res -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (res > 0) return 1;
	else if (res < 0) return -1;
	else return 0;
}

bool cross(PP x, PP y) {
	P a = x.first;
	P b = x.second;
	P c = y.first;
	P d = y.second;
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b)
			swap(a, b);
		if (c > d)
			swap(c, d);
		if (c <= b && a <= d)
			return true;
	}
	else if (ab <= 0 && cd <= 0)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<PP>arr;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		arr.push_back({ {x1,y1},{x2,y2} });
	}
	
	for (int i = 0; i < 3001; i++) {
		parent[i] = i;
		sum[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (cross(arr[i], arr[j]))
				merge(i, j);
		}
	}

	int res = 0, num = 0;
	for (int i = 0; i < n; i++) {
		if (find(i) == i) {
			num++;
			res = max(res, sum[i]);
		}
	}
	cout << num << "\n" << res;
	return 0;
}