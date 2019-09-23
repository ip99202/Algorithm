#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int>arr;
int cnt;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n - 1; i++) {
		if (arr[i + 1] - arr[i] == 1)
			cnt++;
	}
	if (cnt == n - 1)
		printf("0");
	else if (cnt == n - 2 && (arr[1] - arr[0] == 2 || arr[n - 1] - arr[n - 2] == 2))
		printf("1");
	else if (cnt == n - 2)
		printf("2");
	else {
		int mx = 0, idx = 0;
		for (int i = 0; i < n; i++) {
			while (idx < n - 1 && arr[idx + 1] <= arr[i] + n - 1)
				idx++;
			mx = max(mx, idx - i + 1);
		}
		printf("%d", n - mx);
	}
	int bb;
	if (arr[n - 2] - arr[0] < arr[n - 1] - arr[1])
		bb = arr[n - 1] - arr[1] - (n - 2);
	else
		bb = arr[n - 2] - arr[0] - (n - 2);
	printf("\n%d", bb);
}

