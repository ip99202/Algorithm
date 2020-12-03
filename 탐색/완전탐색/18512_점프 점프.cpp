#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, y, a, b; cin >> x >> y >> a >> b;
	int xp = a, yp = b, cnt = 0;
	while (cnt < 100) {
		if (xp == yp) {
			cout << xp;
			return 0;
		}
		if (xp > yp)
			yp += y;
		else
			xp += x;
		cnt++;
	}
	cout << -1;
	return 0;
}