#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string arr;

int main() {
	cin >> arr;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] >= 65 && arr[i] < 97)
			cout << arr[i];
	}
}