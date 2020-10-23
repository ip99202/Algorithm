#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	stack<int>s;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		s.push(x);
	}
	int now = s.top();
	int res = 1;
	while (!s.empty()) {
		if (s.top() > now) {
			now = s.top();
			res++;
		}
		s.pop();
	}
	cout << res;
}