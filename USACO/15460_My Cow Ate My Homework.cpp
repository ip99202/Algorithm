#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>arr;
vector<int>sum;
vector<int>minn;
vector<int>result;
double res, temp;

int main() {
	int n;
	scanf("%d", &n);
	arr.resize(n + 1);
	sum.resize(n + 1);
	minn.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if (i == 1) {
			sum[1] = arr[1];
			continue;
		}
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = n; i > 0; i--) {
		if (i == n) {
			minn[i] = arr[i];
			continue;
		}
		minn[i] = min(minn[i + 1], arr[i]);
	}
	for (int i = 1; i < n - 1; i++) {
		temp = (double)(sum[n] - sum[i] - minn[i + 1]) / (double)(n - i - 1);
		if (temp == res)
			result.push_back(i);
		else if (temp > res) {
			result.clear();
			result.push_back(i);
			res = temp;
		}
	}
	for (int i = 0; i < result.size(); i++)
		printf("%d\n", result[i]);
}