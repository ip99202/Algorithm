#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<int>arr;
string num;

int main() {
	int x;
	for (int i = 0; i < 3; i++) {
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	cin >> num;
	if (num[0] == 'A')
		cout << arr[0];
	if (num[0] == 'B')
		cout << arr[1];
	if (num[0] == 'C')
		cout << arr[2];
	cout << ' ';
	if (num[1] == 'A')
		cout << arr[0];
	if (num[1] == 'B')
		cout << arr[1];
	if (num[1] == 'C')
		cout << arr[2];
	cout << ' ';
	if (num[2] == 'A')
		cout << arr[0];
	if (num[2] == 'B')
		cout << arr[1];
	if (num[2] == 'C')
		cout << arr[2];
}