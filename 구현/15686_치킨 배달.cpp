#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<math.h>
using namespace std;
typedef pair<int, int>P;
int check[14];
vector<P>store, home;
int n, m, res = INT_MAX;

void dis() {
	int sum = 0;
	vector<int>len(home.size(), INT_MAX);
	for (int i = 0; i < home.size(); i++) {
		for (int j = 0; j < store.size(); j++) {
			if (check[j] == 0)
				continue;
			len[i] = min(len[i], (abs(home[i].first - store[j].first) + abs(home[i].second - store[j].second)));
		}
	}
	for (int i = 0; i < len.size(); i++) 
		sum += len[i];
	res = min(res, sum);
}

void cal(int now, int cnt) {
	if (cnt == m) {
		dis();
		return;
	}
	for (int i = now; i < store.size(); i++) {
		if (check[i] == 0) {
			check[i] = 1;
			cal(i, cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int arr[51][51];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				store.push_back({ i,j });
			if (arr[i][j] == 1)
				home.push_back({ i,j });
		}
	}
	cal(0, 0);
	cout << res;
	return 0;
}