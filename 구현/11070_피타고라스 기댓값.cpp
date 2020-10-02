#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
typedef pair<double, double>P;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<P>arr(n + 1, { 0,0 });
		for (int i = 0; i < m; i++) {
			int a, b, p, q; cin >> a >> b >> p >> q;
			arr[a].first += p;
			arr[a].second += q;
			arr[b].first += q;
			arr[b].second += p;
		}
		int maxx = 0, minn = INT_MAX;
		for (int i = 1; i <= n; i++) {
			double exp;
			if (arr[i].first == 0 && arr[i].second == 0)
				exp = 0;
			else {
				exp = arr[i].first * arr[i].first / (arr[i].first * arr[i].first + arr[i].second * arr[i].second);
				exp = exp * 1000;
			}
			maxx = max(maxx, (int)exp);
			minn = min(minn, (int)exp);
		}
		cout << maxx << "\n" << minn << "\n";
	}
	return 0;
}