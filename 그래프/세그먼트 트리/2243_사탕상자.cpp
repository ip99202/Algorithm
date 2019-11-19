#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll>seg;
int h = 1;

void update(int i, ll x) {
	i += h - 1;
	seg[i] += x;
	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
}

int query(ll num, int nodeNum, int nodeL, int nodeR) {
	if (nodeNum * 2 - h + 1 > 1000000)
		return nodeNum - h + 1;
	int mid = (nodeL + nodeR) / 2;
	if (num <= seg[nodeNum * 2])
		return query(num, nodeNum * 2, nodeL, mid);
	else
		return query(num - seg[nodeNum * 2], nodeNum * 2 + 1, mid + 1, nodeR);
}

int main() {
	int n;
	scanf("%d", &n);
	while (1000000 > h)
		h <<= 1;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			ll b;
			scanf("%lld", &b);
			int t = query(b, 1, 1, h);
			update(t, -1);
			printf("%d\n", t);
		}
		else {
			int b;
			ll c;
			scanf("%d %lld", &b, &c);
			update(b, c);
		}
	}
}