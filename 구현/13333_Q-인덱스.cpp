#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	for (int i = 0; i <= 10000; i++) {
		int st = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
		int end = upper_bound(arr.begin(), arr.end(), i) - arr.begin();
		for (int j = st; j <= end; j++) {
			if (i == n - j) {
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}