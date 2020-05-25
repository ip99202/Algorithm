#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int res = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k >= arr[i]) {
			res += k / arr[i];
			k = k % arr[i];
		}
	}
	cout << res;
	return 0;
}