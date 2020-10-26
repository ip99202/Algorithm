#include<iostream>
#include<string>
using namespace std;

int main() {
	int k = 1;
	while (true) {
		char a, b;
		cin >> a >> b;
		if (a == '#' && b == '#')
			break;
		cout << "Case " << k << "\n";
		int n;
		cin >> n;
		getchar();
		for (int j = 1; j <= n; j++) {
			string arr;
			getline(cin, arr);
			for (int i = 0; i < arr.length(); i++) {
				if (arr[i] == a || arr[i] == b || arr[i] == a - 32 || arr[i] == b - 32)
					arr[i] = '_';
			}
			cout << arr << "\n";
		}
		cout << "\n";
		k++;
	}
}