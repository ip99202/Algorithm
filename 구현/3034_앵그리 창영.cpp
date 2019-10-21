#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int n, h, w;
	scanf("%d%d%d", &n, &h, &w);
	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		if (m <= h || m <= w)
			printf("DA\n");
		else if (sqrt(h * h + w * w) >= m)
			printf("DA\n");
		else
			printf("NE\n");
	}
}