#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
typedef pair<int, int>P;
bool visited[20001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << "\n";
			continue;
		}
		queue<int>q;
		q.push(1);
		memset(visited, false, sizeof(visited));
		visited[1] = true;
		vector<P>arr(200001);
		arr[1].first = -1; arr[1].second = 1;
		while (q.size()) {
			int x, y;
			int now = q.front();
			q.pop();
			x = (now * 10) % n;
			if (!visited[x]) {
				arr[x].first = now;
				arr[x].second = 0;
				if (x == 0) break;
				visited[x] = true;
				q.push(x);
			}

			y = (now * 10 + 1) % n;
			if (!visited[y]) {
				arr[y].first = now;
				arr[y].second = 1;
				if (y == 0) break;
				visited[y] = true;
				q.push(y);
			}
		}
		vector<int>res;
		for (int i = 0; i != -1; i = arr[i].first)
			res.push_back(arr[i].second);
		if (res.size() > 100)
			cout << "BREK" << "\n";
		else {
			while (res.size()) {
				cout << res.back();
				res.pop_back();
			}
			cout << "\n";
		}
	}
	return 0;
}