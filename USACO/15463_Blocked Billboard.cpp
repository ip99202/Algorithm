#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int map[3003][3003];
int cnt, temp;

int main() {
	for (int i = 0; i < 3; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int a = x1 + 1000; a < x2 + 1000; a++) {
			for (int b = y1 + 1000; b < y2 + 1000; b++) {
				map[a][b]++;
				if (map[a][b] == 1 && i != 2)
					temp++;
			}
		}
	}
	for (int i = 0; i < 3003; i++) {
		for (int j = 0; j < 3003; j++) {
			if (map[i][j] > 1)
				cnt++;
		}
	}
	printf("%d", temp - cnt);
}