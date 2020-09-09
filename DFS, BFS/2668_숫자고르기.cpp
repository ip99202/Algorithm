#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<deque>
#include<queue>
#include<cstring>
using namespace std;
int n;
int visited[100];
int arr[101];

void dfs(int n) {
	if (visited[n] == 2) return;
	visited[n]++;
	dfs(arr[n]);
}

void init() {
	int i;
	for (i = 1; i < n + 1; i++) {
		if (visited[i] < 2) visited[i] = 0;
	}
}

int main() {
	int result = 0;
	cin >> n;
	for (int i = 1; i < n + 1; i++) cin >> arr[i];

	for (int i = 1; i < n; i++) {
		if (visited[i] != 2) {
			dfs(i);
			init();
		}
	}

	for (int i = 1; i < n + 1; i++) {
		if (visited[i] == 2) result++;
	}

	cout << result << endl;
	for (int i = 1; i < n + 1; i++) {
		if (visited[i] == 2) cout << i << endl;
	}
	return 0;
}
