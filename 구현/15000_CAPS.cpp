#include<iostream>
using namespace std;

int main() {
	string n;
	cin >> n;
	for (int i = 0; i < n.length(); i++) {
		cout << (char)(n[i] - 32);
	}
}