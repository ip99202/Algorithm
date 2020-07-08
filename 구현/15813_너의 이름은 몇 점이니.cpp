#include<iostream>
#include<algorithm>
using namespace std;
char arr[101];
int sum;

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", &arr);
	for (int i = 0; i < n; i++) {
		sum += arr[i] - 'A' + 1;
	}
	printf("%d", sum);
	return 0;
}