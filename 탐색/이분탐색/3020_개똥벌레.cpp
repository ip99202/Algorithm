#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int under[500001], upper[500001], up, down, minn = 999999999, cnt;

int main() {
	int n, h;
	scanf("%d%d", &n, &h);
	for (int i = 0; i < n / 2; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		under[a]++;
		upper[b]++;
		down = max(down, b);
		up = max(up, a);
	}
	for (int i = up; i >= 1; i--)
		under[i] += under[i + 1];
	for (int i = down; i >= 1; i--)
		upper[i] += upper[i + 1];
	for (int i = 1; i <= h; i++) {
		int temp = under[i] + upper[h - i + 1];
		if (temp < minn) {
			cnt = 1;
			minn = temp;
		}
		else if (temp == minn)
			cnt++;
	}
	printf("%d %d", minn, cnt);
}