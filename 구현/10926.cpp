#include <stdio.h>
#include <string.h>
int main()
{
	char str[51];
	scanf("%s", str);
	int len;
	len = strlen(str);
	str[len] = '?';
	str[len + 1] = '?';
	str[len + 2] = '!';
	str[len + 3] = 0;
	printf("%s", str);
	return 0;
}