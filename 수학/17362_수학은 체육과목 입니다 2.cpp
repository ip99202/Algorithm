#include<iostream>	
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	if (n % 8 == 1)
		cout << 1;
	else if (n % 8 == 2)
		cout << 2;
	else if (n % 8 == 3)
		cout << 3;
	else if (n % 8 == 4)
		cout << 4;
	else if (n % 8 == 5)
		cout << 5;
	else if (n % 8 == 6)
		cout << 4;
	else if (n % 8 == 7)
		cout << 3;
	else if (n % 8 == 0)
		cout << 2;
	return 0;
}