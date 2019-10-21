#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int a, b, c;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		long long mul = pow(a, b / 2);
		return mul * mul % c;
	}
	else {
		long long mul = pow(a, b / 2);
		long long temp = mul * mul % c;
		return a * temp % c;
	}
}

int main() {
	scanf("%d%d%d", &a, &b, &c);
	printf("%d", pow(a, b));
}