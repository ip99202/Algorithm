#include<iostream>
using namespace std;
int bug[21][21];
int res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	bug[1][1] = 1;
	for (int i = 2; i < 21; i++) {
		for (int j = 1; j < i; j++) {
			if (j % 2 == 0) {
				if (i - j < 4)
					bug[i][j] += bug[i - 1][j];
			}
			else {
				if (i - j < 3)
					bug[i][j] += bug[i - 1][j];
			}
			bug[i][i] += bug[i - 1][j];
		}
	}
	for (int i = 1; i <= n; i++) 
		res += bug[n][i];
	cout << res;
	return 0;
}