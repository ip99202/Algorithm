#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int res[10], check[10];

void go(int loc, int n, int cnt) {
	if (loc == cnt) {
		for (int i = 0; i < cnt; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			check[i] = 1;
			res[loc] = i;
			go(loc + 1, n, cnt);
			check[i] = 0;
			res[loc] = 0;
		}
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;
	go(0, n, m);
}