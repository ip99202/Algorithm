#include<iostream> 
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	if (n <= k) {
		cout << 0;
		return 0;
	}
	int result;
	for (result = 0; ; result++) {
		int cnt = 0;
		int tmp = n;
		while (tmp) {
			if (tmp % 2)
				cnt++;
			tmp /= 2;
		}
		if (cnt <= k)
			break;
		n++;
	}
	cout << result;
	return 0;
}