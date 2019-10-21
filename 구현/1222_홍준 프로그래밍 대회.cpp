#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll arr[2000001];

void go(int x) {
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			arr[i]++;
			if (i != x / i)
				arr[x / i]++;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		go(a);
	}
	ll cnt = 0;
	for (int i = 0; i <= 2000000; i++) {
		if (arr[i] < 2)
			continue;
		cnt = max(cnt, arr[i] * i);
	}
	printf("%lld", cnt);
}