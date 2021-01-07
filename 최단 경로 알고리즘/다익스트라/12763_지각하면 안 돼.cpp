#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, t, m, l, res = 1e9;
bool flag = false;
struct go {
	int target, time, cost;
};

vector<go>arr[101];

void bfs(int now, int time, int mon) {
	if (now == n) {
		res = min(res, m - mon);
		return;
	}
	for (int i = 0; i < arr[now].size(); i++) {
		go next = arr[now][i];
		if (next.cost <= mon && next.time <= time) {

			bfs(next.target, time - next.time, mon - next.cost);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> t >> m >> l;
	for (int i = 0; i < l; i++) {
		int a, b, time, cost;
		cin >> a >> b >> time >> cost;
		arr[a].push_back({ b,time,cost });
		arr[b].push_back({ a,time,cost });
	}
	bfs(1, t, m);
	if (res == 1e9)
		cout << -1;
	else
		cout << res;
	return 0;
}