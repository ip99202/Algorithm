#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int st = 1;
	int end = arr[n - 1] - arr[0];
	int res = 0;
	while (st <= end) {
		int mid = (st + end) / 2;
		int now = arr[0], cnt = 1;
		for (int i = 1; i < n; i++) {
			if (now + mid <= arr[i]) {
				now = arr[i];
				cnt++;
			}
		}
		if (cnt >= m) {
			res = max(res, mid);
			st = mid + 1;
		}
		else if (cnt < m)
			end = mid - 1;
	}
	cout << res;
	return 0;
}