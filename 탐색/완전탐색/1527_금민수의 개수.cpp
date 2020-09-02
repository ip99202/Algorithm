#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string>
using namespace std;
int cnt, a, b;

void go(long long num) {
	if (num > b)
		return;
	if (num >= a && num <= b)
		cnt++;
	go(num * 10 + 4);
	go(num * 10 + 7);
}

int main() {
	scanf("%d %d", &a, &b);
	go(4);
	go(7);

	printf("%d", cnt);
}