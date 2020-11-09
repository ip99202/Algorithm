#include<iostream>
#include<algorithm>
#include<vector>	
#include<math.h>
using namespace std;
typedef pair<int, int>P;

int ccw(int x1, int x2, int x3, int y1, int y2, int y3) {
	int temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
	if (temp > 0)
		return 1;
	else if (temp < 0)
		return -1;
	else
		return 0;
}

bool cross(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4) {
	if (ccw(x1, x2, x3, y1, y2, y3) * ccw(x1, x2, x4, y1, y2, y4) < 0 &&
		ccw(x1, x3, x4, y1, y3, y4) * ccw(x2, x3, x4, y2, y3, y4) < 0) {
		return true;
	}
	return false;
}

int main() {
	int x1, x2, x3, x4, y1, y2, y3, y4;
	scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

	if (cross(x1, x2, x3, x4, y1, y2, y3, y4))
		printf("1");
	else
		printf("0");
	return 0;
}