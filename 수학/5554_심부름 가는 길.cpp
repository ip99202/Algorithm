#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int a; cin >> a;
		sum += a;
	}
	cout << sum / 60 << "\n" << sum % 60;
	return 0;
}