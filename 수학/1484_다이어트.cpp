#include<iostream>
#include<algorithm>
#include<stack>
#include<math.h>
using namespace std;
typedef long long ll;
stack<ll>res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll g;
	cin >> g;
	ll end = sqrt(g);
	for (ll i = 1; i <= end; i++) {
		if (g % i == 0) {
			ll a = i, b = g / i;
			ll x = (a + b) / 2, y = (b - a) / 2;
			if (x <= y || y == 0 || (b - a) % 2 != 0) continue;
			res.push(x);
		}
	}
	if (!res.size())
		cout << "-1";
	while (res.size()) {
		cout << res.top() << "\n";
		res.pop();
	}
	return 0;
}