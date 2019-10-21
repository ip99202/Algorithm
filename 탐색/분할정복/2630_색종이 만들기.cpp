#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int paper[200][200];
int w_pa, b_pa, n;

void serch(int n, int x, int y) {
	bool c_flag = true;
	int flag = paper[x][y];
	if (n == 1) {
		if (flag == 0)
			w_pa++;
		else if (flag == 1)
			b_pa++;
	}
	else {
		for (int i = x; i < x + n; i++) {
			for (int j = y; j < y + n; j++) {
				if (flag != paper[i][j])
					c_flag = false;
			}
		}
		if (c_flag == true) {
			if (flag == 0) {
				w_pa++;
				return;
			}
			else if (flag == 1) {
				b_pa++;
				return;
			}
		}
		else {
			int num = n / 2;
			serch(num, x, y);
			serch(num, x + num, y);
			serch(num, x, y + num);
			serch(num, x + num, y + num);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &paper[i][j]);
	serch(n, 1, 1);
	printf("%d\n%d", w_pa, b_pa);
}