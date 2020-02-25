#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[31][2];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cin.tie(NULL);
	int d, k;
	cin >> d >> k;
	arr[1][0] = 1;
	arr[2][1] = 1;
	for (int i = 3; i < 31; i++) {
		arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
		arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
	}
	for (int i = 1; i < 10000; i++) {
		for (int j = 1; j < 10000; j++) {
			if (i * arr[d][0] + j * arr[d][1] == k) {
				cout << i << "\n" << j;
				return 0;
			}
			if (i * arr[d][0] + j * arr[d][1] > k)
				break;
		}
	}
	return 0;
}