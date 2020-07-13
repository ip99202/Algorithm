#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	string tmp; cin >> tmp;
	stack<char>arr;
	arr.push(tmp[0]);
	for (int i = 1; i < n; i++) {
		while (arr.top() < tmp[i] && k > 0) {
			arr.pop();
			k--;
			if (arr.empty()) break;
		}
		arr.push(tmp[i]);
	}
	while (k--) 
		arr.pop();
	stack<char>res;
	while (!arr.empty()) {
		res.push(arr.top());
		arr.pop();
	}
	while (!res.empty()) {
		cout << res.top();
		res.pop();
	}
	return 0;
}