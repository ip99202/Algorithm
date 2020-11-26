#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a, t, x;

int cal(int q, int k) {
	if (q == x)
		t--;
	if (t == 0) {
		cout << k;
		return 1;
	}
	else
		return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> t >> x;
	int k = 0, roop = 2;
	while (true) {
		for (int i = 1; i <= 4; i++) {
			if (k >= a)
				k = 0;
			if (i % 2 == 1) {
				if (cal(0, k))
					return 0;
			}
			else {
				if (cal(1, k))
					return 0;
			}
			k++;
		}
		for (int i = 0; i < roop * 2; i++) {
			if (k >= a)
				k = 0;
			if (i >= roop) {
				if (cal(1, k))
					return 0;
			}
			else {
				if (cal(0, k))
					return 0;
			}
			k++;
		}
		roop++;
	}
	return 0;
}