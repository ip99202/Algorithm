#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int l, p; cin >> l >> p;
	for (int i = 0; i < 5; i++) {
		int x; cin >> x;
		cout << x - l * p << " ";
	}
	return 0;
}