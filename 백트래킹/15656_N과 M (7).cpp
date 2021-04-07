#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v, arr;
int n, m;
bool check[10];

void go(int cnt, int here) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			//check[i] = true;
			v.push_back(arr[i]);
			go(cnt + 1, i + 1);
			v.pop_back();
			//check[i] = false;
		}
	}
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	arr.resize(n + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end());
	go(0, 1);
}