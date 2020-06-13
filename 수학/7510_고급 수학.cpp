#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int arr[3];
		for (int j = 0; j < 3; j++)
			scanf("%d", &arr[j]);
		sort(arr, arr + 3);
		if (pow(arr[0], 2) + pow(arr[1], 2) == pow(arr[2], 2))
			printf("Scenario #%d:\nyes\n\n", i);
		else
			printf("Scenario #%d:\nno\n\n", i);
	}
	return 0;
}