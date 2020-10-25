#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
pair<int, int>arr[100001];

int main() {
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[i].first = x;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		res = max(res, arr[i].second - i);
	cout << res + 1;
}
