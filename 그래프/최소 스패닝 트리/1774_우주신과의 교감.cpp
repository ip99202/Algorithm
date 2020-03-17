#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>	
#define INF 999999999
using namespace std;
typedef pair<double, pair<int, int>>PP;
typedef pair<int, int>P;
vector<PP>arr;
vector<P>dis;
int parent[1001], k;
double res;

int find(int n) {
	if (parent[n] < 0) return n;
	parent[n] = find(parent[n]);
	return parent[n];
}

void merge(int a, int b, int num) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[b] = a;
	res += arr[num].first;
}

int main() {
	int n, m;
	fill(parent, parent + 1001, -1);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		dis.push_back(P(x, y));
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double len = sqrt(pow(dis[i].first - dis[j].first, 2)
				+ pow(dis[i].second - dis[j].second, 2));
			arr.push_back({ len,{ i,j } });
			k++;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		x = find(x);
		y = find(y);
		if (x == y) continue;
		parent[x] = y;
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < k; i++) {
		merge(arr[i].second.first, arr[i].second.second, i);
	}
	printf("%.2lf", res);
}