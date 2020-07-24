#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int x; cin >> x;
		sum += x;
	}
	cout << sum;
	return 0;
}