#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;
vector<P>rest;
ll res, bessie;

int main() {
	ll l, n, rf, rb;
	scanf("%lld%lld%lld%lld", &l, &n, &rf, &rb);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		rest.push_back(P(b, a));
	}
	sort(rest.begin(), rest.end(), greater<P>());
	ll idx = 0, dis = 0;
	while (true) {
		if (idx == n) break;
		dis = max(dis, rest[idx].second);
		if (dis > rest[idx].second) {
			idx++;
			continue;
		}
		if (rest[idx].second * rb == rest[idx].second * rf) {
			idx++;
			continue;
		}
		res += (rest[idx].second * rf - (rest[idx].second * rb + bessie)) * rest[idx].first;
		idx++;
		bessie += rest[idx - 1].second * rf - (rest[idx - 1].second * rb + bessie);
	}
	printf("%lld", res);
}