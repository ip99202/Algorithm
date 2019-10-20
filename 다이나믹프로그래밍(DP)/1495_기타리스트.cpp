#include<iostream>
using namespace std;
int dp[2000][2000];
int st[1000];
int n, s, m;

void volume(int num) {
	if (num == 1) {
		if (s + st[1] <= m)
			dp[num][s + st[1]] = 1;
		if (s - st[1] >= 0)
			dp[num][s - st[1]] = 1;
	}
	for (int i = 0; i <= m; i++) {
		if (dp[num - 1][i] == 1) {
			if (i + st[num] <= m)
				dp[num][i + st[num]] = 1;
			if (i - st[num] >= 0)
				dp[num][i - st[num]] = 1;
		}
	}
}

int main() {
	int flag = 0, res;
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++)
		cin >> st[i];
	for (int i = 1; i <= n; i++)
		volume(i);
	for (int i = 0; i <= m; i++) {
		if (dp[n][i] == 1) {
			res = i;
			flag = 1;
		}
	}
	if (flag == 1)
		cout << res;
	else
		cout << -1;
}