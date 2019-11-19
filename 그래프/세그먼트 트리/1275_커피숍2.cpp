#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll>seg;
int h = 1;

void update(int i, ll val) {
	i += h - 1;
	seg[i] = val;
	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
}

ll query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L > nodeR || R < nodeL)
		return 0;
	else if (L <= nodeL && nodeR <= R)
		return seg[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, nodeNum * 2, nodeL, mid) + query(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	while (n > h)
		h <<= 1;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		update(i, x);
	}
	for (int i = 0; i < q; i++) {
		int x, y;
		ll a, b;
		scanf("%d %d %lld %lld", &x, &y, &a, &b);
		if (x > y) {
			int temp;
			temp = y;
			y = x;
			x = temp;
		}
		printf("%lld\n", query(x, y, 1, 1, h));
		update(a, b);
	}
}