#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll>arr;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll s, c, sum = 0;
	cin >> s >> c;
	arr.resize(s + 1);
	for (int i = 0; i < s; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	ll st = 1, end = 1000000000;
	while (st <= end) {
		ll mid = (st + end) / 2;
		int num = 0;
		for (int i = 0; i < s; i++)
			num += arr[i] / mid;
		if (num >= c)
			st = mid + 1;
		else
			end = mid - 1;
	}
	cout << sum - end * c;
	return 0;
}