#include<iostream>
#include<string>
using namespace std;
int arr[53];
int ans[53];
string a;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x]++;
	}
	getchar();
	getline(cin, a);
	for (int i = 0; i < n; i++) {
		if (a[i] >= 'A' && a[i] <= 'Z')
			ans[a[i] - 'A' + 1]++;
		else if (a[i] >= 'a' && a[i] <= 'z')
			ans[a[i] - 'a' + 27]++;
		else if (a[i] == ' ')
			ans[0]++;
	}
	bool flag = true;
	for (int i = 0; i < 53; i++) {
		if (arr[i] != ans[i])
			flag = false;
	}
	if (flag == false)
		cout << 'n';
	else
		cout << 'y';
	return 0;
}