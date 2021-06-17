#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
vector<int>col(16, -1);
int n;

bool check(int now) {
	for (int i = 0; i < now; i++) {
		if (col[now] == col[i])
			return false;
		if (abs(col[now] - col[i]) == now - i)
			return false;
	}
	return true;
}

int dfs(int now) {
	if (now == n)
		return 1;
	int res = 0;
	for (int i = 0; i < n; i++) {
		col[now] = i;
		if (check(now))
			res += dfs(now + 1);
		col[now] = -1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cout << dfs(0);
	return 0;
}