#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	ll num = 0;
	if (n % 2 == 0 || n % 5 == 0) {
		cout << "-1";
		return  0;
	}
	for (int i = 1; i <= n; i++) {
		num = (10 * num + 1) % n;
		if (num == 0) {
			cout << i;
			return 0;
		}
	}
	return 0;
}