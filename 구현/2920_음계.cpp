#include <stdio.h>
int main()
{
	int arr[9] = { 0, }, cnt = 7;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 7; i++) {
		if (arr[i] < arr[i + 1]) {
			cnt++;
		}
	}
	for (int i = 0; i < 7; i++) {
		if (arr[i] > arr[i + 1]) {
			cnt--;
		}
	}
	if (cnt == 14) {
		printf("ascending");
	}
	else if (cnt == 0) {
		printf("descending");
	}
	else {
		printf("mixed");
	}
	return 0;
}