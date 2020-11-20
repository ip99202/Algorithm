#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
typedef pair<int, int>P;
typedef pair<P, double>PP;
vector<PP>arr;

double cal(P a, P b) {
	return pow((a.first - b.first), 2) + pow((a.second - b.second), 2);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr[i].first.first = x;
		arr[i].first.second = y;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i].second < cal(arr[i].first, arr[j].first))
				arr[i].second = cal(arr[i].first, arr[j].first);
		}
	}
	int k = 999999999, res = 0;
	for (int i = 0; i < n; i++) {
		if (k > arr[i].second) {
			k = arr[i].second;
			res = i;
		}
	}
	printf("%d %d", arr[res].first.first, arr[res].first.second);
}