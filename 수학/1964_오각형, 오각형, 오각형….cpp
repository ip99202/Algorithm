#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	cout << (3 * (n * n + n) / 2 + n + 1) % 45678 << endl;
}
