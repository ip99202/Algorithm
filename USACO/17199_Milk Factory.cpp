#include<iostream>
#include<vector>
using namespace std;
int arr[101];
vector<int>v;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a]++;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			v.push_back(i);
		}
	}
	if (v.size() == 1)
		printf("%d", v.front());
	else
		printf("-1");
}