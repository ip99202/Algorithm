#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>	
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
priority_queue<P, vector<P>, greater<P>>pq;
long long tree[1000001];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &tree[i]);
	int lo = 0, hi = 1000000000;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > mid)
				sum += tree[i] - mid;
		}
		if (sum < m)
			hi = mid;
		else
			lo = mid;
	}
	printf("%d", lo);
}