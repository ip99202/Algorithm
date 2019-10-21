#include <iostream>
#include <math.h>
using namespace std;
int cnt, r, c;

void solve(int n, int y, int x, int go) {
	if (y == r && x == c) {
		printf("%d", cnt);
		return;
	}

	// c와 r이 지금 나누어지고있는 부분에 포함되어 있다면 다시 분할
	if ((x <= c && c < x + go) && (y <= r && r < y + go)) {
		solve(n / 2, y, x, go / 2);
		solve(n / 2, y, x + go / 2, go / 2);
		solve(n / 2, y + go / 2, x, go / 2);
		solve(n / 2, y + go / 2, x + go / 2, go / 2);
	}
	else { // 사각형 크기만큼
		cnt += go * go;
		return;
	}
}

int main() {
	int n;
	scanf("%d %d %d", &n, &r, &c);
	n = pow(2, n);
	solve(n, 0, 0, n);
}
