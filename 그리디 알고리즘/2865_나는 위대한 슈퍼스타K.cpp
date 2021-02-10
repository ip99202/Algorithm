#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<double>arr(n + 1);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int i;
			double s;
			cin >> i >> s;
			if (arr[i] < s)
				arr[i] = s;
		}
	}
	double res = 0;
	sort(arr.begin(), arr.end(), greater<double>());
	for (int i = 0; i < k; i++)
		res += arr[i];
	cout << fixed;
	cout.precision(1);
	cout << res;
	return 0;
}