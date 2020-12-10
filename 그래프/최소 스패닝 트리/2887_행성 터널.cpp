#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<math.h>
#include<queue>
using namespace std;
typedef pair<int, int>P;
typedef pair<int, P>PP;
vector<PP>cost;
int n, res, cnt;
int parent[100000];

struct pl {
	int x, y, z, num;
};
pl arr[100000];

bool cmpx(const pl& p1, const pl& p2) {
	return p1.x > p2.x;
}
bool cmpy(const pl& p1, const pl& p2) {
	return p1.y > p2.y;
}
bool cmpz(const pl& p1, const pl& p2) {
	return p1.z > p2.z;
}

int find(int n) {
	if (n == parent[n]) return n;
	parent[n] = find(parent[n]);
	return parent[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	parent[a] = b;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].z);
		arr[i].num = i;
		parent[i] = i;
	}
	sort(arr, arr + n, cmpx);
	for (int i = 0; i < n - 1; i++)
		cost.push_back({ abs(arr[i].x - arr[i + 1].x),{arr[i].num,arr[i + 1].num} });
	sort(arr, arr + n, cmpy);
	for (int i = 0; i < n - 1; i++)
		cost.push_back({ abs(arr[i].y - arr[i + 1].y),{arr[i].num,arr[i + 1].num} });
	sort(arr, arr + n, cmpz);
	for (int i = 0; i < n - 1; i++)
		cost.push_back({ abs(arr[i].z - arr[i + 1].z),{arr[i].num,arr[i + 1].num} });
	sort(cost.begin(), cost.end(), greater<PP>());

	for (int i = cost.size() - 1; i >= 0; i--) {
		if (cnt == n - 1) break;
		if (find(cost[i].second.first) != find(cost[i].second.second)) {
			cnt++;
			res += cost[i].first;
			merge(cost[i].second.first, cost[i].second.second);
		}
	}
	printf("%d", res);
}