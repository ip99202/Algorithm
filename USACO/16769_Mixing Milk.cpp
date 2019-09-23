#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
int arr[3][2];

int main() {
	int a;
	for (int i = 0; i < 3; i++)
		scanf("%d%d", &arr[i][0], &arr[i][1]);
	for (int i = 0; i < 100; i++) {
		if (arr[(i + 1) % 3][0] < arr[i % 3][1] + arr[(i + 1) % 3][1]) {
			arr[i % 3][1] = arr[(i + 1) % 3][1] + arr[i % 3][1] - arr[(i + 1) % 3][0];
			arr[(i + 1) % 3][1] = arr[(i + 1) % 3][0];
		}
		else {
			arr[(i + 1) % 3][1] = arr[i % 3][1] + arr[(i + 1) % 3][1];
			arr[i % 3][1] = 0;
		}
	}
	for (int i = 0; i < 3; i++)
		printf("%d\n", arr[i][1]);
}