#include <stdio.h>
#include <string.h>
int main() {
	int n[6] = { 0, };
	int res = 0;
	int num = 0;
	int temp = 0;
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 4; i++) {
			scanf("%d", &temp);
			n[j] += temp;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (res < n[i]) {
			res = n[i];
			num = i;
		}
	}
	printf("%d %d", num + 1, res);
	return 0;
}
