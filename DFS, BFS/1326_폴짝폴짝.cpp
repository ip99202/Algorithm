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
int fr[10001];
bool visited[10001];
queue<P>q;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &fr[i]);
	int a, b;
	scanf("%d%d", &a, &b);
	q.push(P(a, 0));
	while (!q.empty()) {
		if (a == b) {
			printf("0");
			return 0;
		}
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		int jump = fr[now];
		for (int i = now; i <= n; i += jump) {
			if (i > n) break;
			if (visited[i] == false) {
				q.push(P(i, cnt + 1));
				visited[i] = true;
				if (visited[b] == true) {
					printf("%d", q.back().second);
					return 0;
				}
			}
		}
		for (int i = now; i > 0; i -= jump) {
			if (i <= 0) break;
			if (visited[i] == false) {
				q.push(P(i, cnt + 1));
				visited[i] = true;
				if (visited[b] == true) {
					printf("%d", q.back().second);
					return 0;
				}
			}
		}
	}
	if (visited[b] == false) {
		printf("-1");
		return 0;
	}
}