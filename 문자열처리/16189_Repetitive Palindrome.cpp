#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string s, k;
	int n;
	cin >> s;
	cin >> n;
	k = s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] != k[len - i - 1]) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}