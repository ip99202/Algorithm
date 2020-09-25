#include<iostream>
#include<vector>
using namespace std;
int arr[1001][1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!arr[i][j]) continue;
			arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;
			res = max(res, arr[i][j]);
		}
	}
	cout << res * res;
	return 0;
}