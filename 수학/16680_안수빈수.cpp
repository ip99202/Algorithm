#include<iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll len = 1;
		ll num = n;
		int cnt = 0;
		while (num) {
			num = num / 10;
			len *= 10;
			cnt++;
		}
		if (cnt % 2 == 0)
			len *= 10;
		cout << n * len - n << "\n";
	}
	return 0;
}