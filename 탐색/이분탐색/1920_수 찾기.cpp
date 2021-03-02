#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int arr[100001];
int n, m;

void binarySearch(int n, int key) {
	int st = 0;
	int end = n - 1;
	int mid;
	while (end - st >= 0) {
		mid = (st + end) / 2;
		if (arr[mid] == key) {
			printf("1\n");
			return;
		}
		else if (arr[mid] > key)
			end = mid - 1;
		else
			st = mid + 1;
	}
	printf("0\n");
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		binarySearch(n, x);
	}
}