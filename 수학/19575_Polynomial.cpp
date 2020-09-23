#include<iostream>
#include<algorithm>
#include<vector>
#define mod 1000000007
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, x; cin >> n >> x;
	ll sum = 0;
	for (int i = 0; i < n + 1; i++) {
		int a, b; cin >> a >> b;
		if (i == 0) 
			sum = a;
		else {
			sum = (sum * x + a) % mod;
		}
	}
	cout << sum;
	return 0;
}