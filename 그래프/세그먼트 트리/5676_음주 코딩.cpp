#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll>seg;
int h = 1, n, k;

void update(int i, int n) {
	i += h - 1;
	seg[i] = n;
	while (i > 1) {
		i /= 2;
		if (seg[i * 2] == 0 || seg[i * 2 + 1] == 0) {
			seg[i] = 0;
		}
		else if ((seg[i * 2] > 0 && seg[i * 2 + 1] > 0) || (seg[i * 2] < 0 && seg[i * 2 + 1] < 0)) {
			seg[i] = 1;
		}
		else seg[i] = -1;
	}
}

ll query(int L, int R, int nodeNun, int nodeL, int nodeR) {
	if (L > nodeR || R < nodeL)
		return 1;
	else if (L <= nodeL && R >= nodeR)
		return seg[nodeNun];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, nodeNun * 2, nodeL, mid) * query(L, R, nodeNun * 2 + 1, mid + 1, nodeR);
}

int main() {
	while (scanf("%d%d", &n, &k) != EOF) {
		while (n > h)
			h <<= 1;
		seg.resize(h * 2);
		for (int i = 1; i <= n; i++) {
			ll x;
			scanf("%lld", &x);
			update(i, x);
		}
		for (int i = 0; i < k; i++) {
			char x;
			getchar();
			scanf("%c", &x);
			if (x == 'C') {
				int a, b;
				scanf("%d%d", &a, &b);
				update(a, b);
			}
			else {
				int a, b;
				scanf("%d%d", &a, &b);
				if (query(a, b, 1, 1, h) > 0)
					printf("+");
				else if (query(a, b, 1, 1, h) < 0)
					printf("-");
				else
					printf("0");
			}
		}
		printf("\n");
		h = 1;
		seg.clear();
	}
}