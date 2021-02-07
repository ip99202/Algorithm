#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[42][42];
string str1, str2;

void print(int i, int j) {
	if (i == 0 || j == 0)
		return;
	if (str1[i] == str2[j]) {
		print(i - 1, j - 1);
		cout << str1[i];
	}
	else {
		if (arr[i][j - 1] == arr[i][j])
			print(i, j - 1);
		else
			print(i - 1, j);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a, b; cin >> a >> b;
	str1 = "0" + a;
	str2 = "0" + b;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (str1[i] == str2[j])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
		}
	}
	print(a.length(), b.length());
	return 0;
}