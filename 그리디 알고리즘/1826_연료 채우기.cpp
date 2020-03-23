#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int>P;
priority_queue<int>pq;
P st[10001];
int cnt;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &st[i].first, &st[i].second);
	sort(st, st + n);
	int dis, gas;
	scanf("%d%d", &dis, &gas);
	int i = 0;
	while (gas < dis) {
		for (i; i < n; i++) {
			if (st[i].first > gas)
				break;
			if (st[i].first <= gas)
				pq.push(st[i].second);
		}
		if (pq.empty())
			break;
		cnt++;
		gas += pq.top();
		pq.pop();
	}
	if (gas < dis)
		printf("-1");
	else
		printf("%d", cnt);
}