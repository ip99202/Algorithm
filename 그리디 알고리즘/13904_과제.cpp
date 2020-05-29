#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>P;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<P>arr(n + 1);
	arr[0] = P(101, 0);
	vector<bool>check(1001, false);
	for (int i = 1; i <= n; i++)
		cin >> arr[i].second >> arr[i].first;
	sort(arr.begin(), arr.end(), greater<P>());
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[arr[i].second]) {
			check[arr[i].second] = true;
			res += arr[i].first;
		}
		else {
			for (int j = arr[i].second - 1; j > 0; j--) {
				if (!check[j]) {
					check[j] = true;
					res += arr[i].first;
					break;
				}
			}
		}
	}
	cout << res;
	return 0;
}