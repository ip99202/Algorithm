#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	vector<int>arr;
	cin >> a >> b;
	arr.push_back(0);
	for (int i = 1; i < 100; i++) {
		for (int j = 0; j < i; j++) {
			arr.push_back(i);
		}
	}
	int res = 0;
	for (int i = a; i <= b; i++) {
		res += arr[i];
	}
	cout << res;
	return 0;
}