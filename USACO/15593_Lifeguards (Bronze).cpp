#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int>P;
int arr[1001];
vector<P>num;
int res = 999999999, temp;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		num.push_back(P(a, b));
		for (int i = a + 1; i <= b; i++) {
			arr[i]++;
		}
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = num[i].first + 1; j <= num[i].second; j++) {
			if (arr[j] == 1)
				cnt++;
		}
		res = min(res, cnt);
	}
	for (int i = 1; i <= 1000; i++) {
		if (arr[i] != 0)
			temp++;
	}
	printf("%d", temp - res);
}