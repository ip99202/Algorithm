#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int x, int y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	if (n == 0 & m == 0) {
		cout << 0;
		return 0;
	}
	if (n < 0) n *= -1;
	if (m < 0) m *= -1;
	if (gcd(n, m) == 1)
		cout << 1;
	else
		cout << 2;
	return 0;
}