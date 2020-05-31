#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int>P;

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<P>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());
	int res = 0;
	priority_queue<P, vector<P>, greater<P>>q;
	q.push(P(arr[0].second, arr[0].first));
	for (int i = 1; i < n; i++) {
		while (q.top().first <= arr[i].first) {
			q.pop();
		}
		q.push(P(arr[i].second, arr[i].first));
		res = max(res, (int)q.size());
	}
	cout << res;
	return 0;
}