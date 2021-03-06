#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>	
#define INF 999999999
using namespace std;
int p[10001], mon[10001];

int find(int n) {
	if (p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (mon[a] > mon[b])
		p[a] = b;
	else
		p[b] = a;
}

int main() {
	fill(p, p + 10001, -1);
	int n, m, k, res = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &mon[i]);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int v, w;
		v = min(a, b);
		w = max(a, b);
		merge(v, w);
	}
	for (int i = 1; i <= n; i++) {
		if (p[i] == -1)
			res += mon[i];
	}
	if (res > k)
		printf("Oh no");
	else
		printf("%d", res);
}