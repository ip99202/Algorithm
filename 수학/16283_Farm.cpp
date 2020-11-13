#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, n, w; cin >> a >> b >> n >> w;
	int res = 0, x, y;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			if (a * i + b * j == w && i + j == n) {
				res++;
				x = i;
				y = j;
			}
		}
	}
	if (res > 1 || res == 0)
		cout << -1;
	else
		cout << x << " " << y;
	return 0;
}