#include <stdio.h>
#include <string.h>
int main() {
	char arr[1000001] = { 0, };
	int alp[27] = { 0, };
	int al = 0, cnt = 0, err = 0, res = 0, len = 0;
	scanf("%s", arr);
	len = strlen(arr);
	for (int i = 0; i < len; i++) {
		al = arr[i];
		if (al < 97) {
			al = al + 32;
		}
		alp[al - 97]++;
	}
	for (int i = 0; i < 27; i++) {
		if (cnt < alp[i]) {
			cnt = alp[i];
			res = i + 65;
		}
	}
	for (int i = 0; i < 27; i++) {
		if (cnt == alp[i]) {
			err++;
		}
	}
	if (err > 1) {
		printf("%c", '?');
	}
	else {
		printf("%c", res);
	}
	return 0;
}