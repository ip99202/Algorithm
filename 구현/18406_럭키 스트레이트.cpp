#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string arr; cin >> arr;
	int len = arr.size();
	int left = 0, right = 0;
	for (int i = 0; i < len / 2; i++) {
		left += (arr[i] - '0');
		right += (arr[len - i - 1] - '0');
	}
	if (left == right) cout << "LUCKY";
	else cout << "READY";
	return 0;
}