#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	while (!cin.eof() && cin >> n >> k) {
		ll res = 1;
		if (n == 0) {
			cout << 1 << "\n";
			continue;
		}
		for (int i = 2; i <= sqrt(k); i++) {
			int primeK = 0;
			while (k % i == 0) {
				k /= i;
				primeK++;
			}
			int primeN = 0;
			if (primeK > 0) {
				for (int j = i; j <= n; j *= i)
					primeN += n / j;
			}
			res *= pow(i, min(primeK, primeN));
			if (k < i)
				break;
		}
		if (k > 1 && k < n)
			res *= k;
		cout << res << "\n";
	}
	return 0;
}