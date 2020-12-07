#include <stdio.h>
#include <string.h>
int main() {
	int cnt = 0, len = 0, tem = 0;
	char arr[201] = { 0, };
	int alp[27] = { 0, };
	while (1) {
		cnt = 0;
		int alp[27] = { 0, };
		gets(arr);
		len = strlen(arr);
		if (arr[0] == '*') break;
		for (int i = 0; i < len; i++) {
			tem = arr[i];
			alp[tem - 97]++;
		}
		for (int i = 0; i < 26; i++) {
			if (alp[i] == 0) {
				cnt++;
			}
		}
		if (cnt == 0) {
			printf("Y\n");
		}
		else {
			printf("N\n");
		}
	}
	return 0;
}