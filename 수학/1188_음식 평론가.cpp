#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int r = gcd(n, m);
	printf("%d", m - r);
}