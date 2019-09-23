#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
int arr[101];

int main() {
	int a, b, x, y;
	scanf("%d%d%d%d", &a, &b, &x, &y);
	if (x > y)
		swap(x, y);
	if (a > b)
		swap(a, b);
	int dis = b - a;
	if (dis == 0) {
		printf("0");
		return 0;
	}
	int res2 = 0;
	res2 = b - a;

	int res = 0;
	res += abs(x - a);
	res += abs(y - b);
	printf("%d", min(res, res2));

}