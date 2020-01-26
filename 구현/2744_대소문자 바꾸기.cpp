#include <stdio.h>
#include <string.h>
int main() {
	char arr[101] = { 0, };
	int ch = 0;
	scanf("%s", arr);
	int len = strlen(arr);
	for (int i = 0; i < len; i++) {
		ch = arr[i];
		if (ch < 96) {
			ch += 32;
		}
		else {
			ch -= 32;
		}
		arr[i] = ch;
	}
	printf("%s", arr);
	return 0;
}