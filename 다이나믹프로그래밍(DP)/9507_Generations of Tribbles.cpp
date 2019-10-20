#include<iostream>
#include<vector>
using namespace std;
long long num[100];

long long koong(long long n) {
	if (num[n] != 0)
		return num[n];
	num[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
	return num[n];
}

int main() {
	num[0] = 1;
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