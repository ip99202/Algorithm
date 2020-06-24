#include<iostream>
using namespace std;

int main() {
	int p1, p2, p3, p4;
	int x, y, r;
	scanf("%d %d %d %d", &p1, &p2, &p3, &p4);
	scanf("%d %d %d", &x, &y, &r);
	if (p1 == x)
		printf("1");
	else if (p2 == x)
		printf("2");
	else if (p3 == x)
		printf("3");
	else if (p4 == x)
		printf("4");
	else
		printf("0");
}