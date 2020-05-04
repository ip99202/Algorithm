#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>	
#define INF 999999999
using namespace std;
int p[201], des[1001];

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
	fill(p, p + 201, -1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			if (x == 1)
				merge(i, j);
		}
	}
	for (int i = 0; i < m; i++)
		scanf("%d", &des[i]);
	bool flag = true;
	for (int i = 1; i < m; i++) {
		if (find(des[i - 1]) != find(des[i]))
			flag = false;
	}
	if (flag == true)
		printf("YES");
	else
		printf("NO");
}