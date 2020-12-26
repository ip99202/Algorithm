#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>P;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, l; cin >> n >> l;
	vector<P>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());
	int res = 0, now = 0;
	for (int i = 0; i < n; i++) {
		if (now >= arr[i].second)
			continue;
		now = max(now, arr[i].first);
		int cnt = (arr[i].second - (now + 1)) / l + 1;
		res += cnt;
		now += cnt * l;
	}
	cout << res;
	return 0;
}