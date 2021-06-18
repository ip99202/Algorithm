#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
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
	for (int i = here; i <= n; i++) {
		v.push_back(i);
		go(cnt + 1, i);
		v.pop_back();
	}
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	go(0, 1);
}