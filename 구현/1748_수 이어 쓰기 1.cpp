#include<iostream>
using namespace std;

int main() {
	int num, cnt = 1;
	int res = 0, plus = 10;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		if (i == plus) {
			plus *= 10;
			cnt++;
		}
		res += cnt;
	}
	cout << res;
}