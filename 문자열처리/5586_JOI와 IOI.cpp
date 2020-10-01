#include <stdio.h>
#include <string.h>
int main()
{
	char arr[10001] = { 0, };
	int num1 = 0, num2 = 0;
	scanf("%s", arr);
	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == 'J' && arr[i + 1] == 'O' && arr[i + 2] == 'I') {
			num1++;
		}
		if (arr[i] == 'I' && arr[i + 1] == 'O' && arr[i + 2] == 'I') {
			num2++;
		}
	}
	printf("%d\n%d", num1, num2);
	return 0;
}