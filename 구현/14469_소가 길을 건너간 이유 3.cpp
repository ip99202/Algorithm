#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef pair<int, int>P;
typedef long long ll;
vector<P>arr;
ll res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back(P(a, b));
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		if (i == 0) {
			res = arr[i].first + arr[i].second;
			continue;
		}
		if (res <= arr[i].first)
			res = arr[i].first + arr[i].second;
		else
			res = res + arr[i].second;
	}
	cout << res;
	return 0;
}