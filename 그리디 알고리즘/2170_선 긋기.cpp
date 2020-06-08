#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<P>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());
	ll res = 0, now = -1000000001;
	for (int i = 0; i < n; i++) {
		now = max(now, arr[i].first);
		if (now >= arr[i].second)
			continue;
		res += arr[i].second - now;
		now = arr[i].second;
	}
	cout << res;
	return 0;
}