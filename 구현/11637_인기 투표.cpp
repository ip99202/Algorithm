#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int>arr(n + 1);
		int widx = 0, wval = 0, tmp = 0, sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (tmp < arr[i]) {
				tmp = arr[i];
				widx = i;
				wval = arr[i];
			}
			sum += arr[i];
		}
		sort(arr.begin(), arr.end(), greater<int>());
		if (arr[1] == wval) {
			cout << "no winner " << "\n";
			continue;
		}
		if (wval * 2 > sum)
			cout << "majority winner " << widx << "\n";
		else if (wval * 2 <= sum)
			cout << "minority winner " << widx << "\n";
	}
	return 0;
}