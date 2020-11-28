#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		int ab, bc, ca; cin >> ab >> bc >> ca;
		int res = 0;
		for (int i = 0; i <= min(a, b); i++) {
			int tmp = ab * i;
			int na = a - i;
			int nb = b - i;
			if (bc < ca) {
				tmp += min(na, c) * ca;
				int nc = c - min(na, c);
				tmp += min(nb, nc) * bc;
			}
			else {
				tmp += min(nb, c) * bc;
				int nc = c - min(nb, c);
				tmp += min(na, nc) * ca;
			}
			res = max(res, tmp);
		}
		cout << res << "\n";
	}
	return 0;
}