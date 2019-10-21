#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t, n, sum = 0;
	double res = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			double y;
			cin >> x >> y;
			sum += x;
			res += x * y;
		}
		cout << sum << ' ' << res / sum << '\n';
		sum = 0;
		res = 0;
	}
}