#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int x1, y1, x2, y2;
int x3, y3, x4, y4;

int main() {
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

	if (y1 >= y4 || y2 <= y3 || x1 >= x4 || x3 >= x2)
		printf("%d\n", (y2 - y1) * (x2 - x1));
	else if (y4 >= y2 && y3 <= y1) {
		if (x1 <= x3 && x3 <= x2 && x2 <= x4)
			printf("%d\n", (y2 - y1) * (x3 - x1));
		else if (x3 <= x1 && x1 <= x4 && x4 <= x2)
			printf("%d\n", (y2 - y1) * (x2 - x4));
		else printf("%d\n", (y2 - y1) * (x2 - x1));
	}

	else if (x3 <= x1 && x2 <= x4) {
		if (y2 >= y4 && y4 >= y1 && y1 >= y3)
			printf("%d\n", (y2 - y4) * (x2 - x1));
		else if (y4 >= y2 && y2 >= y3 && y3 >= y1)
			printf("%d\n", (y3 - y1) * (x2 - x1));
		else printf("%d\n", (y2 - y1) * (x2 - x1));
	}
	else printf("%d\n", (y2 - y1) * (x2 - x1));
}