#include <iostream>
#include <algorithm>
using namespace std;

int	main() {
	int arr[9], res[7];
	int sum = 0, se = 0;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			se = sum - arr[i] - arr[j];
			if (se == 100) {
				if (i == j) continue;
				arr[i] = 0;
				arr[j] = 0;
				sort(arr, arr + 9, greater<int>());
				for (int k = 0; k < 7; k++) {
					res[k] = arr[k];
				}
				sort(res, res + 7);
				for (int i = 0; i < 7; i++) printf("%d\n", res[i]);
				sum = 0;
				break;
			}
		}
	}
}