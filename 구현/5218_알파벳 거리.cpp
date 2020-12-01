#include <stdio.h>
#include <string.h>
int main() {
	char arr1[20] = { 0, };
	char arr2[20] = { 0, };
	int n = 0, len = 0, d1 = 0, d2 = 0, dis = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s", arr1, arr2);
		len = strlen(arr1);
		printf("%s", "Distances:");
		for (int i = 0; i < len; i++) {
			d1 = arr1[i];
			d2 = arr2[i];
			if (d2 >= d1) {
				dis = d2 - d1;
			}
			else {
				dis = (d2 + 26) - d1;
			}
			printf(" %d", dis);
		}
		printf("\n");
	}
	return 0;
}