#include<iostream>
#include<vector>
using namespace std;

int main() {
	while (true) {
		int n;
		scanf("%d", &n);
		int arr[30];
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				printf("%d ", arr[i]);
				continue;
			}
			if (arr[i - 1] != arr[i])
				printf("%d ", arr[i]);
		}
		printf("$\n");

	}
}