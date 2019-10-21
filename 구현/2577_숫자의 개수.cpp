#include <stdio.h>
int main()
{
	int x = 0, y = 0, z = 0;
	int num[11];
	int res = 0;
	int cnt = 0;
	int p_num = 0;
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	res = x * y * z;

	for (int i = 0; i < 11; i++) {
		num[i] = 0;
	}
	while (1)
	{
		res = res / 10;
		cnt++;
		if (res < 1) {
			break;
		}
	}
	res = x * y * z;
	for (int i = 1; i < cnt + 1; i++) {
		p_num = res % 10;
		num[p_num] += 1;
		res = res / 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", num[i]);
	}
	return 0;
}