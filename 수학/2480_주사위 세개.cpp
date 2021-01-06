#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int>arr(7, 0);
	for (int i = 0; i < 3; i++) {
		int x; cin >> x;
		arr[x]++;
	}
	int res = 0, maxx = 0, cnt = 0;
	for (int i = 1; i < 7; i++) {
		if (arr[i] == 3)
			res += (10000 + i * 1000);
		else if (arr[i] == 2)
			res += (1000 + i * 100);
		else if (arr[i] == 1) {
			cnt++;
			maxx = max(maxx, i);
		}
	}
	if (cnt == 3)
		res += maxx * 100;
	cout << res;
	return 0;
}