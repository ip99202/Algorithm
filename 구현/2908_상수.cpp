#include<stdio.h>
int main() {
	char a[5], b[5], c, d, f, g;

	scanf("%s", a);
	scanf("%s", b);

	c = a[0];
	d = a[2];
	f = b[0];
	g = b[2];

	a[0] = d;
	a[2] = c;
	b[0] = g;
	b[2] = f;

	for (int i = 0; i < 2; i++)
	{
		if (a[i] < b[i]) {
			printf("%c%c%c", b[0], b[1], b[2]);
			break;
		}
		else if (a[i] > b[i]) {
			printf("%c%c%c", a[0], a[1], a[2]);
			break;
		}
	}
	return 0;
}