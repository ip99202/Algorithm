#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	if (b == "AND") {
		if (a == "true" && c == "true") {
			cout << "true";
			return 0;
		}
		else {
			cout << "false";
			return 0;
		}
	}
	else if (b == "OR") {
		if (a == "false" && c == "false") {
			cout << "false";
			return 0;
		}
		else {
			cout << "true";
			return 0;
		}
	}
}

