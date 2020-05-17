#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, string>P;
vector<P>arr;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		int len = x.length();
		arr.push_back(P(len, x));
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < n; i++) {
		if (arr[i - 1].second == arr[i].second)
			arr[i].first = 100;
	}
	for (int i = 0; i < n; i++) {
		if (arr[i].first == 100)
			continue;
		cout << arr[i].second << "\n";
	}
}