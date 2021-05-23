#include<iostream>
#include<vector>
using namespace std;
vector<long long>v;

int main() {
	int n, m;
	long long left = 1, mid, sum = 0;
	long long right = 500000000001;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		long long x;
		scanf("%lld", &x);
		v.push_back(x);
	}
	while (left <= right) {
		sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < v.size(); i++)
			sum += mid / v[i];
		if (sum >= m)
			right = mid - 1;
		else
			left = mid + 1;
	}
	printf("%lld", left);
	return 0;
}