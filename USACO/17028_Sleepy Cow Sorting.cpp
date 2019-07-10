#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	int i, temp;
	for (i = n - 1; i >= 0; i--) {
		if (i == n - 1)
			temp = v[i];
		else if (temp > v[i])
			temp = v[i];
		else
			break;
	}
	printf("%d", i + 1);
}