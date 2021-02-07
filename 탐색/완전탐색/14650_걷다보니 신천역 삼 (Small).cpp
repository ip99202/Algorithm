#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int res[10];

void go(string arr) {
	if (arr.length() > 9)
		return;
	if (stoi(arr) % 3 == 0) {
		res[arr.length()]++;
	}
	go(arr + "0");
	go(arr + "1");
	go(arr + "2");
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	go("1");
	go("2");
	cout << res[n];
	return 0;
}