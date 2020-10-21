#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#define mod 1000000
using namespace std;
vector<int>arr, cal;
int res;

void calculate(int n) {
	cal[0] = 1;
	for (int i = 1; i <= n; i++) {
		cal[i] = (cal[i - 1] * 2) % mod;
	}
}

void go(int from, int to) {
	if (from == 0)
		return;
	int now = arr[from];
	int sub;
	for (int i = 1; i <= 3; i++)
		if (now != i && to != i)
			sub = i;
	if (to != now) {
		go(from - 1, sub);
		res = (res + cal[from - 1]) % mod;
	}
	else
		go(from - 1, to);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	arr.resize(n + 1);
	cal.resize(n + 1);
	int a, b, c; cin >> a >> b >> c;
	for (int i = 1; i <= a; i++) {
		int x; cin >> x;
		arr[x] = 1;
	}
	for (int i = 1; i <= b; i++) {
		int x; cin >> x;
		arr[x] = 2;
	}
	for (int i = 1; i <= c; i++) {
		int x; cin >> x;
		arr[x] = 3;
	}
	calculate(n);
	go(n, arr[n]);
	cout << arr[n] << "\n" << res;
	return 0;
}