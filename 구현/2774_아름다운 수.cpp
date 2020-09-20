#include<iostream>
#include<algorithm>
using namespace std;
int arr[10];

int main() {
	int t;
	cin >> t;
	while (t--) {
		string num;
		int res = 0;
		cin >> num;
		for (int i = 0; i < num.length(); i++) {
			int temp = num[i] - '0';
			arr[temp]++;

		}
		for (int i = 0; i < 10; i++)
			if (arr[i] != 0)
				res++;
		printf("%d\n", res);
		fill(arr, arr + 10, 0);
	}
}