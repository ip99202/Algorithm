#include<iostream>
int main(void)
{
	int h, m;
	scanf("%d %d", &h, &m);

	if (m - 45 >= 0)
		m -= 45;
	else if (m - 45 < 0)
	{
		m += 15;
		h--;
	}

	if (h < 0)
		h = 23;

	printf("%d %d", h, m);
	return 0;
}