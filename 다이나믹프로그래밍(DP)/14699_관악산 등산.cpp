#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
vector<int>height;
vector<vector<int>>arr;
int dp[5001];

int dfs(int now) {
	if (dp[now])
		return dp[now];
	for (int i = 0; i < arr[now].size(); i++) 
		dp[now] = max(dp[now], dfs(arr[now][i]));
	return dp[now] += 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	height.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> height[i];
	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (height[a] >= height[b])
			swap(a, b);
		arr[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
		cout << dfs(i) << "\n";
	return 0;
}