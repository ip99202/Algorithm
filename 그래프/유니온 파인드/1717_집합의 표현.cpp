#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>	
#define INF 999999999
using namespace std;
int p[1000001];

int find(int n) {
	if (p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	fill(p, p + 1000001, -1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &c, &a, &b);
		if (c == 0) {
			merge(a, b);
		}
		else {
			if (find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}