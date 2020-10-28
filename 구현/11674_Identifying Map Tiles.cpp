#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string n;
	cin >> n;
	int index = 0, depth = n.size();
	int width = pow(2, n.size());
	int x = 0, y = 0;
	while (true) {
		if (index == depth) {
			cout << n.size() << ' ' << x << ' ' << y;
			break;
		}
		if (n[index] == '0') {
			width = width / 2;
			index += 1;
		}
		else if (n[index] == '1') {
			width = width / 2;
			x += width;
			index += 1;
		}
		else if (n[index] == '2') {
			width = width / 2;
			y += width;
			index += 1;
		}
		else if (n[index] == '3') {
			width = width / 2;
			x += width;
			y += width;
			index += 1;
		}
	}

}