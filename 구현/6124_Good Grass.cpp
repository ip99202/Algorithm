#include<iostream>
#include<algorithm>
using namespace std;
int arr[101][101];
int sum, res, x, y;

int main() {
	int nr, nc;
	cin >> nr >> nc;
	for (int i = 1; i <= nr; i++) {
		for (int j = 1; j <= nc; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= nr - 3; i++) {
		for (int j = 1; j <= nc - 3; j++) {
			sum = 0;
			for (int k = 0; k < 3; k++) {
				for (int h = 0; h < 3; h++) {
					sum += arr[k + i][h + j];
				}
			}
			if (res < sum) {
				res = sum;
				x = i;
				y = j;
			}
		}
	}
	cout << res << '\n' << x << ' ' << y;
}