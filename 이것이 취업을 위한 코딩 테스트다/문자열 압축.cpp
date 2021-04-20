#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	int res = s.size(), len = s.size();
	for (int i = 1; i <= len/2; i++) {
		string target, tmp;
		target = s.substr(0, i);
		int cnt = 1;
		for (int j = i; j < len; j += i) {
			if (s.substr(j, i) == target) {
				cnt++;
			}
			else {
				if (cnt > 1)
					tmp += to_string(cnt);
				tmp += target;
				target = s.substr(j, i);
				cnt = 1;
			}
		}
		if (cnt > 1)
			tmp += to_string(cnt);
		tmp += target;
		res = min(res, (int)tmp.size());
	}
	cout << res;
	return 0;
}