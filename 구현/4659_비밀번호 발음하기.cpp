#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef pair<char, int>P;
char vowel[5] = { 'a','e','i','o','u' };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true) {
		string arr; cin >> arr;
		if (arr == "end") break;
		int same = 0;
		bool end = false;
		for (int i = 1; i < arr.length(); i++) {
			if (arr[i] == arr[i - 1] && arr[i] != 'e' && arr[i] != 'o') {
				cout << '<' << arr << "> " << "is not acceptable.\n";
				end = true;
				break;
			}
		}
		if (end) continue;
		int cnt = 0;
		for (int i = 0; i < arr.length(); i++) {
			for (int j = 0; j < 5; j++) {
				if (arr[i] == vowel[j])
					cnt++;
			}
		}
		if (cnt == 0) {
			cout << '<' << arr << "> " << "is not acceptable.\n";
			continue;
		}
		int v = 0;
		int c = 0;
		for (int i = 0; i < arr.length(); i++) {
			bool flag = false;
			for (int j = 0; j < 5; j++) {
				if (arr[i] == vowel[j]) {
					if (v)
						v++;
					else {
						c = 0;
						v++;
					}
					flag = true;
				}
			}
			if (!flag) {
				if (c)
					c++;
				else {
					v = 0;
					c++;
				}
			}
			if (v > 2 || c > 2) {
				cout << '<' << arr << "> " << "is not acceptable.\n";
				end = true;
				break;
			}
		}
		if (end) continue;
		cout << '<' << arr << "> " << "is acceptable.\n";
	}
	return 0;
}