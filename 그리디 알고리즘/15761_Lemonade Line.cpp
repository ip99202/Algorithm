#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		if (v[i] >= i)
			cnt++;
	}
	cout << cnt;
}