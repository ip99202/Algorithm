#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<int>arr;
	int a, b, c; cin >> a >> b >> c;
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	sort(arr.begin(), arr.end());
	cout << arr[1];
	return 0;
}