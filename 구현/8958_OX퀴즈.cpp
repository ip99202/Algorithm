#include <stdio.h>
#include <string.h>
int main()
{
	int num = 0;
	int poi = 0, po = 0;
	char res[80];
	scanf("%d", &num);
	for (int k = 0; k < num; k++) {
		scanf("%s", res);
		for (int i = 0; i < strlen(res); i++) {
			if (res[i] == 'O') {
				if (res[i] == 'O' && res[i - 1] == 'O') {
					po++;
				}
				poi += 1 + po;
			}
			else {
				po = 0;
			}
		}
		printf("%d\n", poi);
		poi = 0;
		po = 0;
	}
	return 0;
}