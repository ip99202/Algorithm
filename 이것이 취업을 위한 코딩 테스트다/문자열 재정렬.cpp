#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string arr; cin >> arr;
	int len = arr.size();
	vector<char>v;
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (arr[i] >= '0' && arr[i] <= '9')
			sum += (arr[i] - '0');
		else
			v.push_back(arr[i]);
	}
	sort(v.begin(), v.end());
	len = v.size();
	for (int i = 0; i < len; i++)
		cout << v[i];
	cout << sum;
	return 0;
}