#include <stdio.h>
#include <string.h>
int main()
{
	char arr[51] = { 0, };
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, x7 = 0, x8 = 0;
	scanf("%s", arr);
	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == '1' || arr[i] == 'Q' || arr[i] == 'A' || arr[i] == 'Z') {
			x1++;
		}
		else if (arr[i] == '2' || arr[i] == 'W' || arr[i] == 'S' || arr[i] == 'X') {
			x2++;
		}
		else if (arr[i] == '3' || arr[i] == 'E' || arr[i] == 'D' || arr[i] == 'C') {
			x3++;
		}
		else if (arr[i] == '4' || arr[i] == 'R' || arr[i] == 'F' || arr[i] == 'V'
			|| arr[i] == '5' || arr[i] == 'T' || arr[i] == 'G' || arr[i] == 'B') {
			x4++;
		}
		else if (arr[i] == '6' || arr[i] == 'Y' || arr[i] == 'H' || arr[i] == 'N'
			|| arr[i] == '7' || arr[i] == 'U' || arr[i] == 'J' || arr[i] == 'M') {
			x5++;
		}
		else if (arr[i] == '8' || arr[i] == 'I' || arr[i] == 'K' || arr[i] == ',') {
			x6++;
		}
		else if (arr[i] == '9' || arr[i] == 'O' || arr[i] == 'L' || arr[i] == '.') {
			x7++;
		}
		else if (arr[i] == '0' || arr[i] == 'P' || arr[i] == ';' || arr[i] == '/'
			|| arr[i] == '-' || arr[i] == '[' || arr[i] == '\'' || arr[i] == '//' || arr[i] == '=' || arr[i] == ']') {
			x8++;
		}
	}
	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", x1, x2, x3, x4, x5, x6, x7, x8);
	return 0;
}