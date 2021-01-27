#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, k; cin >> n >> k;
	vector<ll>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	ll sum = 0;
	sort(arr.begin(), arr.end(), less<ll>());
	for (ll i = 1; i < n; i++) {
		ll tmp = arr[i] * min(i, k);
		sum += tmp;
	}
	cout << sum;
	return 0;
}