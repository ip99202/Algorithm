#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct V
{
	int id, score, check, time;
};
bool cmp(const struct V& x, const struct  V& y) {
	if (x.score < y.score) return false;
	else if (x.score == y.score) {
		if (x.check > y.check) return false;
		else if (x.check == y.check) {
			if (x.time > y.time) return false;
			else return true;
		}
		else return true;
	}
	else return true;
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n, k, t, m, log[105][105], check[105], time[105];
		vector<V> v;
		cin >> n >> k >> t >> m;
		for (int i = 1; i <= n; i++)
			fill(log[i], log[i] + k + 1, 0);
		fill(check, check + 105, 0);
		fill(time, time + 105, 0);
		for (int i = 0; i < m; i++) {
			int id, j, s;
			cin >> id >> j >> s;
			log[id][j] = max(log[id][j], s);
			check[id]++;
			time[id] = i;
		}

		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= k; j++)
				sum += log[i][j];
			v.push_back({ i, sum, check[i], time[i] });
		}
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < n; i++) {
			if (v[i].id == t) {
				cout << i + 1 << "\n";
				break;
			}
		}
	}
}