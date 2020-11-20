#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		ll sum = 0, res = LLONG_MIN;
		for (int i = 0; i < n; i++) {
			ll x; cin >> x;
			sum += x;
			res = max(res, sum);
			if (sum < 0) sum = 0;
		}
		cout << res << "\n";
	}
	return 0;
}