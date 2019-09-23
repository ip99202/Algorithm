#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
typedef pair<int, int>P;
typedef pair<int, P>PP;
priority_queue<PP, vector<PP>, greater<>>pq;
priority_queue<PP, vector<PP>, greater<>>q;

int main() {
	int n, time = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		pq.push({ a,{b,i} });
	}
	int temp = 0, res = 0;
	while (true) {
		time++;
		if (temp != 0)
			temp--;
		while (!pq.empty() && pq.top().first == time) {
			q.push({ pq.top().second.second,{pq.top().second.first,pq.top().first} });
			pq.pop();
		}
		if (temp == 0) {
			if (!q.empty()) {
				temp = q.top().second.first;
				res = max(res, time - q.top().second.second);
				q.pop();
			}
		}
		if (pq.empty() && q.empty())
			break;
	}
	printf("%d", res);
}
