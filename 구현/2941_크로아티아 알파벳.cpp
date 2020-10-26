#include <stdio.h>
#include <string.h>
int main()
{
	char arr[101] = { 0, };
	int res = 0;
	scanf("%s", arr);
	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == 'c' && arr[i + 1] == '=') {
			res++;
			i++;
		}
		else if (arr[i] == 'c' && arr[i + 1] == '-') {
			res++;
			i++;
		}
		else if (arr[i] == 'd' && arr[i + 1] == 'z' && arr[i + 2] == '=') {
			res++;
			i += 2;
		}
		else if (arr[i] == 'd' && arr[i + 1] == '-') {
			res++;
			i++;
		}
		else if (arr[i] == 'l' && arr[i + 1] == 'j') {
			res++;
			i++;
		}
		else if (arr[i] == 'n' && arr[i + 1] == 'j') {
			res++;
			i++;
		}
		else if (arr[i] == 's' && arr[i + 1] == '=') {
			res++;
			i++;
		}
		else if (arr[i] == 'z' && arr[i + 1] == '=') {
			res++;
			i++;
		}
		else {
			res++;
		}
	}
	printf("%d", res);
	return 0;
}