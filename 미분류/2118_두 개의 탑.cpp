#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>arr;
vector<int>sum;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, res = 0, total = 0;
	cin >> n;
	arr.push_back(-1);
	sum.push_back(0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
		total += x;
		sum.push_back(total);
	}
	for (int i = 0; i <= n; i++) {
		for (int j = i; j < n; j++) {
			if (i == 0) continue;
			int a = min(sum[j] - sum[i], total - (sum[j] - sum[i]));
			res = max(res, min(sum[j] - sum[i - 1], total - (sum[j] - sum[i - 1])));
		}
	}
	cout << res;
	return 0;
}