#include<iostream>
using namespace std;
int arr[1001];
int n, k, cnt = 0;

int main() {
	int i = 0, res = 0;
	scanf("%d %d", &n, &k);
	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}
	while (1) {
		for (i = 0; i <= n; i++) {
			if (arr[i] != 0) {
				cnt++;
				if (cnt == k) {
					res = arr[i];
				}
				arr[i] = 0;
				break;
			}
		}
		if (cnt == k) break;
		for (int j = 1; j * i <= n; j++) {
			if (arr[i * j] != 0) {
				cnt++;
				if (cnt == k) {
					res = arr[i * j];
					break;
				}
				arr[i * j] = 0;
			}
		}
		if (cnt == k)
			break;
	}
	printf("%d", res);
}