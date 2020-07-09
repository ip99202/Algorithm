#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int cnt = 0, res = 0;
	bool flag = false;
	string arr, ans;
	getline(cin, arr);
	getline(cin, ans);
	int len = arr.size();
	int a_len = ans.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < a_len; j++) {
			if (i + a_len > len) {
				flag = false;
				break;
			}
			if (ans[j] != arr[i + j]) {
				flag = false;
				break;
			}
			else {
				cnt++;
				flag = true;
			}
		}
		if (flag == true) {
			res++;
			i += cnt - 1;
		}
		cnt = 0;
		flag = false;
	}
	cout << res;
}