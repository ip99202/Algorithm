#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int k, l, n;
	scanf("%d%d%d", &k, &l, &n);
	int useTime = 0, noTime = 0;
	bool use = false;
	int noUse = 0;
	getchar();
	for (int i = 1; i <= n; i++) {
		char x;
		scanf("%c", &x);
		if (x == '0') {
			useTime = 0;
			noTime++;
			if (noTime >= l && use) {
				printf("%d\n", i);
				use = false;
			}
		}
		else {
			useTime++;
			noTime = 0;
		}
		if (useTime >= k) {
			use = true;
			noUse++;
		}
	}
	if (use)
		printf("%d", n + l - noTime);
	if (noUse == 0)
		printf("NIKAD");
	return 0;
}