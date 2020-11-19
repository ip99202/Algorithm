#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, t; cin >> n >> t;
	int err = 0;
	vector<int>arr(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	ll sum = 0;
	int right = 0, left = 0, res = INT_MAX;
	while (right >= left) {
		int nr = right, nl = left;
		if (sum < t) {
			if (right < n) {
				right++;
				sum += arr[right];
			}
		}
		else {
			if (left <= right) {
				sum -= arr[left];
				left++;
			}
		}
		if (sum >= t)
			res = min(res, right - left + 1);
		if (nr == right && nl == left)
			break;
	}
	if (res == INT_MAX)
		cout << 0;
	else
		cout << res;
	return 0;
}