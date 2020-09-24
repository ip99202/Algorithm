#include<iostream>
#include<algorithm>
#define mod 16769023
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int sum = 2;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 1)
			sum = (sum * 2) % mod;
	}
	cout << sum;
	return 0;
}