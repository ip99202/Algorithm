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
		seg[i] = seg[i * 2] * seg[i * 2 + 1] % 1000000007;
	}
}

ll query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R)
		return seg[nodeNum];
	else if (nodeR < L || R < nodeL)
		return 1;
	int mid = (nodeL + nodeR) / 2;
	return (query(L, R, nodeNum * 2, nodeL, mid) * query(L, R, nodeNum * 2 + 1, mid + 1, nodeR)) % 1000000007;
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	while (n > h)
		h <<= 1;
	seg.resize(h * 2);

	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		update(i, x);
	}

	for (int i = 0; i < m + k; i++) {
		int x, y;
		ll z;
		scanf("%d%d%lld", &x, &y, &z);
		if (x == 1)
			update(y, z);
		else
			printf("%lld\n", query(y, z, 1, 1, h));
	}
}