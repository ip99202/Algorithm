#include <stdio.h>
int main()
{
	int s, res = 0;
	scanf("%d", &s);
	while (1) {
		if (s % 5 == 0) {
			printf("%d", s / 5 + res);
			break;
		}
		else if (s <= 0) {
			printf("-1");
			break;
		}
		s -= 3;
		res++;
	}
	return 0;
}