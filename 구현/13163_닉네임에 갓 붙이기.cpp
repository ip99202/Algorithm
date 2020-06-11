#include <iostream>
#include <string>
using namespace std;
string arr;
string god;
int main() {
	int n, index;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin.get();
		getline(cin, arr);
		index = arr.find(' ');
		god = "god";
		cout << god;
		for (int j = index + 1; j < arr.length(); j++) {
			if (arr[j] == ' ')
				continue;
			cout << arr[j];
		}
		printf("\n");
	}
	return 0;
}