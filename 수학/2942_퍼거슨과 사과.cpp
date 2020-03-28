#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<int, int>P;
typedef pair<int, P>PP;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	int cnt = gcd(a, b);
	for (int i = 1; i <= sqrt(cnt); i++) {
		if (cnt % i != 0) continue;
		cout << i << ' ' << a / i << ' ' << b / i << "\n";
		int tmp = cnt / i;
		if (tmp == i) continue;
		cout << tmp << ' ' << a / tmp << ' ' << b / tmp << "\n";
	}
	return 0;
}