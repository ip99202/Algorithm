#include<iostream>
#include<vector>
using namespace std;
long long num[12];

long long koong(long long n) {
	if (num[n] != 0 || n == 0)
		return num[n];
	num[n] = koong(n - 1) + koong(n - 2) + koong(n - 3);
	return num[n];
}

int main() {
	num[0] = 0;
	num[1] = 1;
	num[2] = 2;
	num[3] = 4;
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", koong(n));
	}
}