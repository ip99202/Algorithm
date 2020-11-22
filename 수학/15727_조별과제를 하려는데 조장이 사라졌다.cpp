#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int res = n / 5;
	if (n % 5 != 0) res++;
	cout << res;
	return 0;
}