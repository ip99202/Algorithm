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
int n, m, w, dist[501];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &w);
		vector<vector<P>> time(n + 1);

		for (int i = 0; i < m; i++) {
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			time[s].push_back(P(e, t));
			time[e].push_back(P(s, t));
		}
		for (int i = 0; i < w; i++) {
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			time[s].push_back(P(e, -t));
		}
		fill(dist, dist + 501, INF);
		dist[1] = 0;
		bool cycle = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int len = time[j].size();
				for (int k = 0; k < len; k++) {
					int to = time[j][k].first;
					int ti = time[j][k].second;
					if (dist[to] > dist[j] + ti) {
						dist[to] = dist[j] + ti;
						if (i == n)
							cycle = true;
					}
				}
			}
		}
		if (cycle)
			printf("YES\n");
		else
			printf("NO\n");
	}
}