#include <stdio.h>
#include <string.h>
int main()
{
	char x[1000000] = { 0, };
	int num = 1;
	gets(x);
	for (int i = 0; i < strlen(x); i++) {
		if (x[i] == ' ') {
			num++;
		}
	}
	if (x[0] == ' ') {
		num--;
	}
	if (x[strlen(x) - 1] == ' ') {
		num--;
	}
	printf("%d", num);
	return 0;
}