#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x == 0) {
			cout << "Case #" << i << ": INSOMNIA\n";
			continue;
		}
		bool arr[10] = { false };
		for (int j = 1;; j++) {
			int tmp = x * j;
			string s = to_string(tmp);
			for (int k = 0; k < s.length(); k++) {
				arr[s[k] - '0'] = true;
			}
			bool flag = false;
			for (int k = 0; k < 10; k++) {
				if (arr[k] == false) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << "Case #" << i << ": " << tmp << "\n";
				break;
			}
		}
	}
	return 0;
}