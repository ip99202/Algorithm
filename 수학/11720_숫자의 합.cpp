#include <stdio.h>
#include <string.h>
int main()
{
	char arr[101] = { 0, };
	int len = 0, res = 0;
	scanf("%d", &len);
	scanf("%s", arr);
	for (int i = 0; i < len; i++) {
		res += (arr[i] - '0');
	}
	printf("%d", res);
	return 0;
}