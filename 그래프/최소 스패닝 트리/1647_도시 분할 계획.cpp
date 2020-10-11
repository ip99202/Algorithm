#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>	
#define INF 999999999
using namespace std;
typedef pair<int, pair<int, int>>P;
vector<P>arr;
int parent[100001], res, temp;

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
	temp = max(temp, arr[num].first);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	fill(parent, parent + 100001, -1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		arr.push_back({ c,{a,b} });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < m; i++)
		merge(arr[i].second.first, arr[i].second.second, i);

	printf("%d", res - temp);
}