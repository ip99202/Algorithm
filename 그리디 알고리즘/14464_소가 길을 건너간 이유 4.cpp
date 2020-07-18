#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, bool>P;
struct cow {
	int st, end;
};
bool operator<(cow t, cow u) {
	return t.end > u.end;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<P>chi;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		chi.push_back({ x,false });
	}
	sort(chi.begin(), chi.end());
	priority_queue<cow, vector<cow>>cow;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cow.push({ a,b });
	}

	int res = 0;
	while (!cow.empty()) {
		for (int i = 0; i < n; i++) {
			if (chi[i].first >= cow.top().st && chi[i].first <= cow.top().end && chi[i].second == false) {
				res++;
				chi[i].second = true;
				break;
			}
		}
		cow.pop();
	}
	cout << res;
	return 0;
}