#include <stdio.h>
int main() {
	int t_price = 0, x_price = 0, i_price = 0;
	scanf("%d", &t_price);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &i_price);
		x_price += i_price;
	}
	printf("%d", t_price - x_price);
	return 0;
}