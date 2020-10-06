#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int>P;
vector<int>arr[100001];
vector<P>ans;
int discover_num[100001];
int cnt;

int dfs(int idx, int parent) {
	int low = discover_num[idx] = ++cnt;
	int c = 0;
	int ret = cnt;
	for (int i = 0; i < arr[idx].size(); i++) {
		int now = arr[idx][i];
		if (!discover_num[now]) {
			low = dfs(now, idx);
			if (low > discover_num[idx]) {
				c = now;
				ans.push_back(P(min(idx, now), max(idx, now)));
			}
			ret = min(ret, low);
		}
		else if (now != parent)
			ret = min(ret, discover_num[now]);
	}
	return ret;
}

int main() {
	int v, e;
	scanf("%d%d", &v, &e);
	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) {
		if (!discover_num[i])
			dfs(i, true);
	}
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
}