#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string arr;
	char goal;
	int cnt = 0;
	while (true) {
		cin >> goal;
		if (goal == '#')
			break;
		getline(cin, arr);
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == goal || arr[i] + 32 == goal)
				cnt++;
		}
		cout << goal << ' ' << cnt << '\n';
		cnt = 0;
	}
}