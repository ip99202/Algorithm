#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
ll arr[1000001][21];
ll value;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		ll idx = 0;
		while (x > 0) {
			arr[i][idx] = x % 2;
			x = x / 2;
			idx++;
		}
		for (int j = idx + 1; j < 20; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < 21; i++) {
		ll one = 0, zero = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j][i] == 1)
				one++;
			else
				zero++;
		}
		value += one * zero * (1 << i);
	}
	cout << value;
	return 0;
}