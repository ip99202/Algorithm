#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int>seg;
int num[100001];
int h = 1;

void update(int i, int x) {
	i += h - 1;
	seg[i] = x;
	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
}

int query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L > nodeR || R < nodeL)
		return 0;
	else if (L <= nodeL && R >= nodeR)
		return seg[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, nodeNum * 2, nodeL, mid) + query(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;дл
		h = 1;
		scanf("%d %d", &n, &m);
		while (n + m > h)
			h <<= 1;
		seg.clear();
		seg.resize(h * 2);
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; i++) {
			update(m + i, 1);
			num[i] = m + i;
		}
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			printf("%d ", query(1, num[x] - 1, 1, 1, h));
			update(num[x], 0);
			update(m - i, 1);
			num[x] = m - i;
		}
		printf("\n");
	}
}