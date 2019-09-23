#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int hi = 1000000000;
int n, m, c;
int arr[111111];

bool go(int x) {
	int cnt = 1;
	for (int i = 1, st = 0; i < n; i++) {
		if (i - st < c && arr[i] <= arr[st] + x)
			continue;
		cnt += 1;
		st = i;
	}
	return cnt <= m;
}

int main() {
	int lo = 0;
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (go(mid))
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	printf("%d", lo);
}