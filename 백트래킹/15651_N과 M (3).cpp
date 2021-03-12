#include<iostream>
#include<vector>
using namespace std;
int check[10];
vector<int>v;

void go(int loc, int n, int cnt) {
	if (loc == cnt) {
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			//check[i] = 1;
			v.push_back(i);
			go(loc + 1, n, cnt);
			//check[i] = 0;
			v.pop_back();
		}
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	go(0, n, m);
}