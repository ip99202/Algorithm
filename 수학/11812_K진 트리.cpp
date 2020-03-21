#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, k, q;
	cin >> n >> k >> q;
	for (int i = 0; i < q; i++) {
		ll x, y, len = 0;
		cin >> x >> y;
		if (k == 1) {
			cout << abs(x - y) << "\n";
			continue;
		}
		while (x != y) {
			if (x > y)
				x = (x + k - 2) / k;
			else
				y = (y + k - 2) / k;
			len++;
		}
		cout << len << "\n";
	}
	return 0;
}