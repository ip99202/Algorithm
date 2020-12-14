#include<iostream>
using namespace std;
int res[41][2];

void fibo() {
	res[0][0] = 1;
	res[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		res[i][0] = res[i - 1][0] + res[i - 2][0];
		res[i][1] = res[i - 1][1] + res[i - 2][1];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	fibo();
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		printf("%d %d\n", res[x][0], res[x][1]);
	}
}