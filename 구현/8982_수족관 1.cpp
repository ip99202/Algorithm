#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int>P;
int dep[40001];
int st_dep[40001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, len, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n / 2 - 1; i++) {
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		if (i == n / 2 - 2)
			len = xx;
		dep[x] = y;
		st_dep[x] = 0;
		if (xx - x > 1) {
			for (int j = x + 1; j < xx; j++) {
				dep[j] = y;
				st_dep[j] = 0;
			}
		}
	}
	int j;
	cin >> a >> b;
	cin >> j;
	for (int i = 0; i < j; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		st_dep[x1] = y1;
		int hei = y1;
		for (int i = x1 - 1; i >= 0; i--) {
			hei = min(dep[i], hei);
			if (st_dep[i] > hei)
				break;
			st_dep[i] = hei;
		}
		hei = y1;
		for (int i = x1 + 1; i < len; i++) {
			hei = min(dep[i], hei);
			if (st_dep[i] > hei)
				break;
			st_dep[i] = hei;
		}
	}
	int res = 0;
	for (int i = 0; i < len; i++) {
		if (dep[i] > st_dep[i])
			res += (dep[i] - st_dep[i]);
	}
	cout << res;
	return 0;
}