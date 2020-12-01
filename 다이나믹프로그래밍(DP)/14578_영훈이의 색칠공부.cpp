#include<iostream>
#include<algorithm>
#include<vector>
#define big 1000000007
using namespace std;
typedef long long ll;
ll arr[100002];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	ll temp = 1;
	arr[1] = 0;
	arr[0] = 1;
	for (ll i = 2; i <= n; i++) {
		temp *= i;
		temp %= big;
		arr[i] = (i - 1) * (arr[i - 1] + arr[i - 2]) % big;
	}
	cout << (temp * arr[n]) % big;
	return 0;
}