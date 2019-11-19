#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1000000000
using namespace std;
typedef long long ll;
vector<ll>min_seg, max_seg;
int h = 1;

void update(int i, int n) {
	i += h - 1;
	min_seg[i] = n;
	max_seg[i] = n;
	while (i > 1) {
		i /= 2;
		min_seg[i] = min(min_seg[i * 2], min_seg[i * 2 + 1]);
		max_seg[i] = max(max_seg[i * 2], max_seg[i * 2 + 1]);
	}
}

ll min_query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L > nodeR || R < nodeL)
		return INF;
	else if (L <= nodeL && R >= nodeR)
		return min_seg[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return min(min_query(L, R, nodeNum * 2, nodeL, mid), min_query(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}

ll max_query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L > nodeR || R < nodeL)
		return 0;
	else if (L <= nodeL && R >= nodeR)
		return max_seg[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return max(max_query(L, R, nodeNum * 2, nodeL, mid), max_query(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (h < n)
		h <<= 1;
	min_seg.resize(h * 2);
	max_seg.resize(h * 2);
	fill(min_seg.begin(), min_seg.end(), INF);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		update(i, x);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld %lld\n", min_query(a, b, 1, 1, h), max_query(a, b, 1, 1, h));
	}
}