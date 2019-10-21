#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int paper[2200][2200];
int f_num, s_num, t_num, n;

void serch(int n, int x, int y) {
	bool c_flag = true;
	int flag = paper[x][y];
	if (n == 1) {
		if (flag == -1)
			f_num++;
		else if (flag == 0)
			s_num++;
		else if (flag == 1)
			t_num++;
	}
	else {
		for (int i = x; i < x + n; i++) {
			for (int j = y; j < y + n; j++) {
				if (flag != paper[i][j]) {
					c_flag = false;
					break;
				}
			}
		}
		if (c_flag == true) {
			if (flag == -1) {
				f_num++;
				return;
			}
			else if (flag == 0) {
				s_num++;
				return;
			}
			else if (flag == 1) {
				t_num++;
				return;
			}
		}
		else {
			int num = n / 3;
			serch(num, x, y);
			serch(num, x + num, y);
			serch(num, x + num * 2, y);
			serch(num, x, y + num);
			serch(num, x + num, y + num);
			serch(num, x + num * 2, y + num);
			serch(num, x, y + num * 2);
			serch(num, x + num, y + num * 2);
			serch(num, x + num * 2, y + num * 2);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &paper[i][j]);
	serch(n, 1, 1);
	printf("%d\n%d\n%d", f_num, s_num, t_num);
}