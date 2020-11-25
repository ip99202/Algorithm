#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int m, n; cin >> m >> n;
		int i = 0, j = 0;
		cout << "1\n";
		while (true) {
			cout << '(' << i << ',' << j << ")\n";
			if (i % 2)
				j--;
			else
				j++;
			if (j >= n || j < 1) {
				i++;
				if (i % 2)
					j--;
				else
					j++;
			}
			if (i == m)
				break;
		}
		for (int i = m - 1; i > 0; i--)
			cout << '(' << i << ',' << "0)\n";
	}
	return 0;
}