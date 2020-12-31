#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
bitset<(1 << 25)>bit;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (bit[n]) continue;
		printf("%d ", n);
		bit[n] = 1;
	}
	return 0;
}