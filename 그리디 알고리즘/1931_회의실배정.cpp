#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>P;

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<P>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].second >> arr[i].first;
	sort(arr.begin(), arr.end());
	int res = 1;
	int now = arr[0].first;
	for (int i = 1; i < n; i++) {
		if (now > arr[i].second)
			continue;
		else {
			res++;
			now = arr[i].first;
		}
	}
	cout << res;
	return 0;
}