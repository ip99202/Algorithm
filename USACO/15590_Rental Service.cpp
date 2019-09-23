#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<long long, long long>P;
long long res1[100001];
vector<P>sell;
vector<long long>rent, cow;
long long sum, ans;

int main() {
	int n, m, r;
	scanf("%d%d%d", &n, &m, &r);
	cow.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &cow[i]);
	sell.resize(m);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &sell[i].second, &sell[i].first);
	rent.resize(r);
	for (int i = 0; i < r; i++)
		scanf("%d", &rent[i]);
	sort(cow.begin(), cow.end(), greater<long long>());
	sort(sell.begin(), sell.end(), greater<P>());
	sort(rent.begin(), rent.end());
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (m <= k) break;
		if (cow[i] > sell[k].second) {
			res1[i] += sell[k].second * sell[k].first;
			cow[i] -= sell[k].second;
			k++;
			while (true) {
				if (m <= k) break;
				if (cow[i] > sell[k].second) {
					res1[i] += sell[k].second * sell[k].first;
					cow[i] -= sell[k].second;
					k++;
				}
				else {
					res1[i] += sell[k].first * cow[i];
					sell[k].second -= cow[i];
					break;
				}
			}
		}
		else {
			res1[i] += sell[k].first * cow[i];
			sell[k].second -= cow[i];
		}
	}
	int len = rent.size() - 1;
	for (int i = cow.size() - 1; i >= 0; i--) {
		if (len < 0)
			break;
		res1[i] = max(res1[i], rent[len--]);
	}
	for (int i = 0; i < n; i++)
		ans += res1[i];
	printf("%lld", ans);
}