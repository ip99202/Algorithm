#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int arr[5];
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}
	int bp = 2000, dp = 2000;
	for (int i = 0; i < 3; i++)
		bp = min(arr[i], bp);
	for (int i = 3; i < 5; i++)
		dp = min(arr[i], dp);
	cout << dp + bp - 50;
}