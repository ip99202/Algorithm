#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int j = 1; j <= n; j++) {
		string arr;
		cin >> arr;
		cout << "String #" << j << "\n";
		for (int i = 0; i < arr.length(); i++) {
			if (arr[i] == 'Z')
				cout << 'A';
			else
				cout << (char)(arr[i] + 1);
		}
		cout << "\n" << "\n";
	}
}