#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr, arr2;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr.push_back(a);
		arr2.push_back(a);
	}
	int cnt = 0;
	sort(arr2.begin(), arr2.end());
	for (int i = 0; i < n; i++) {
		if (arr[i] != arr2[i])
			cnt++;
	}
	printf("%d", cnt - 1);
}