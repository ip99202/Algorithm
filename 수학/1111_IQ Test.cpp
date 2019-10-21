#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int arr[51];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	if (n == 1) {
		printf("A");
		return 0;
	}
	else if (n == 2) {
		if (arr[0] == arr[1]) {
			printf("%d", arr[0]);
			return 0;
		}
		else {
			printf("A");
			return 0;
		}
	}
	int a;
	if (arr[1] == arr[0])
		a = 0;
	else
		a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
	int b = arr[1] - arr[0] * a;
	for (int i = 2; i < n; i++) {
		if ((arr[i - 1] != arr[i - 2]) && (a != (arr[i] - arr[i - 1]) / (arr[i - 1] - arr[i - 2]))) {
			cout << "B";
			return 0;
		}
		if (b != arr[i] - arr[i - 1] * a) {
			cout << "B";
			return 0;
		}
	}
	printf("%d", arr[n - 1] * a + b);
}