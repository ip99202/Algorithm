#include<iostream>
#include<algorithm>
#include<vector>	
#include<math.h>
using namespace std;
typedef pair<int, int>P;

int ccw(int x1, int x2, int x3, int y1, int y2, int y3) {
	long long temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
	if (temp > 0)
		return 1;
	else if (temp < 0)
		return -1;
	else
		return 0;
}

bool cross(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4) {
	if (ccw(x1, x2, x3, y1, y2, y3) * ccw(x1, x2, x4, y1, y2, y4) <= 0 &&
		ccw(x1, x3, x4, y1, y3, y4) * ccw(x2, x3, x4, y2, y3, y4) <= 0) {
		if ((x1 < x3 && x1 < x4 && x2 < x3 && x2 < x4) ||
			(x3 < x1 && x3 < x2 && x4 < x1 && x4 < x2)) return false;
		if ((y1 < y3 && y1 < y4 && y2 < y3 && y2 < y4) ||
			(y3 < y1 && y3 < y2 && y4 < y1 && y4 < y2)) return false;
		return true;
	}
	return false;
}

bool cross_point(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (ccw(x1, x2, x3, y1, y2, y3) * ccw(x1, x2, x4, y1, y2, y4) == 0 &&
		ccw(x1, x3, x4, y1, y3, y4) * ccw(x2, x3, x4, y2, y3, y4) <= 0)
		return true;
	else
		return false;
}

bool cross_line(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (ccw(x1, x2, x3, y1, y2, y3) * ccw(x1, x2, x4, y1, y2, y4) < 0 &&
		ccw(x1, x3, x4, y1, y3, y4) * ccw(x2, x3, x4, y2, y3, y4) <= 0)
		return true;
	else
		return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x1, x2, x3, x4, y1, y2, y3, y4;
		P s1, s2, s3, s4;
		scanf("%d%d%d%d%d%d%d%d", &x3, &y3, &x4, &y4, &x1, &y1, &x2, &y2);
		s1 = P(min(x3, x4), min(y3, y4));
		s2 = P(min(x3, x4), max(y3, y4));
		s3 = P(max(x3, x4), min(y3, y4));
		s4 = P(max(x3, x4), max(y3, y4));
		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}

		if (!cross(x1, x2, s1.first, s2.first, y1, y2, s1.second, s2.second) &&
			!cross(x1, x2, s2.first, s4.first, y1, y2, s2.second, s4.second) &&
			!cross(x1, x2, s4.first, s3.first, y1, y2, s4.second, s3.second) &&
			!cross(x1, x2, s3.first, s2.first, y1, y2, s3.second, s2.second))
			printf("0\n");
		else {
			if (x1 == x2 && x1 == x3) {
				if ((y1 < y4) && (y2 > y3) || (y2 < y4) && (y1 > y3)) {
					printf("4\n");
					continue;
				}
			}
			else if (x1 == x2 && x1 == x3) {
				if ((y1 < y4) && (y2 > y3) || (y2 < y4) && (y1 > y3)) {
					printf("4\n");
					continue;
				}
			}
			else if (y1 == y2 && y1 == y4) {
				if ((x1 < x4) && (x2 > x3) || (x2 < x4) && (x1 > x3)) {
					printf("4\n");
					continue;
				}
			}
			else if (y1 == y2 && y1 == y3) {
				if ((x1 < x4) && (x2 > x3) || (x2 < x4) && (x1 > x3)) {
					printf("4\n");
					continue;
				}
			}
			int point = 0, line = 0;
			if (cross_point(x1, y1, x2, y2, s1.first, s1.second, s2.first, s2.second)) point++;
			if (cross_point(x1, y1, x2, y2, s2.first, s2.second, s4.first, s4.second)) point++;
			if (cross_point(x1, y1, x2, y2, s4.first, s4.second, s3.first, s3.second)) point++;
			if (cross_point(x1, y1, x2, y2, s3.first, s3.second, s1.first, s1.second)) point++;
			if (cross_line(x1, y1, x2, y2, s1.first, s1.second, s2.first, s2.second)) line++;
			if (cross_line(x1, y1, x2, y2, s2.first, s2.second, s4.first, s4.second)) line++;
			if (cross_line(x1, y1, x2, y2, s4.first, s4.second, s3.first, s3.second)) line++;
			if (cross_line(x1, y1, x2, y2, s3.first, s3.second, s1.first, s1.second)) line++;
			printf("%d\n", point / 2 + line);
		}
	}
	return 0;
}