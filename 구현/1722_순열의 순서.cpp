#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long f[21];
bool check[21];

int main() {
	int n, cho;
	cin >> n;
	f[0] = 1;
	for (int i = 1; i < 21; i++)
		f[i] = f[i - 1] * i;

	cin >> cho;

	if (cho == 1) {
		long long k;
		cin >> k;
		vector<int> v;
		v.resize(n);

		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[j] == true)
					continue;
				if (f[n - i - 1] < k)
					k -= f[n - i - 1];
				else {
					v[i] = j;
					check[j] = true;
					break;
				}
			}
		}

		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
	}

	else {
		vector<int> v;
		v.resize(n);

		for (int i = 0; i < n; i++)
			cin >> v[i];

		long long ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < v[i]; j++) {
				if (check[j] == false)
					ans += f[n - i - 1];
			}
			check[v[i]] = true;
		}
		cout << ans + 1;
	}
}