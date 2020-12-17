#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int in, out, num = 0, res = 0;
	for (int i = 0; i < 10; i++) {
		cin >> out >> in;
		num -= out;
		num += in;
		res = max(res, num);
	}
	cout << res;
}