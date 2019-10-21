#include <stdio.h>
int main()
{
	int n_list[6];
	int x = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &x);
		if (x < 40) {
			n_list[i] = 40;
		}
		else {
			n_list[i] = x;
		}
	}
	x = 0;
	for (int i = 0; i < 5; i++) {
		x += n_list[i];
	}
	printf("%d", x / 5);
	return 0;
}