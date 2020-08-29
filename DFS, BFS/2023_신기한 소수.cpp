#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;
int n;

bool check(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

void go(int num, int cnt) {
	if (cnt == n) {
		if (check(num))
			printf("%d\n", num);
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (check(num * 10 + i))
			go(num * 10 + i, cnt + 1);
	}
}

int main() {
	scanf("%d", &n);
	go(2, 1);
	go(3, 1);
	go(5, 1);
	go(7, 1);
}