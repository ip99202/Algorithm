#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a = 1, b = 1, c = 2, d = 2, x = 2, y = 8;
	int e, f, g, h, i, j; cin >> e >> f >> g >> h >> i >> j;
	cout << a - e << " " << b - f << " " << d - g << " " << d - h << " " << x - i << " " << y - j;
	return 0;
}