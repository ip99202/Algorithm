#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	for (int k = 1; k <= t; k++) {
		int n; cin >> n;
		vector<int>arr1(n);
		vector<int>arr2;
		for (int i = 0; i < n; i++)
			cin >> arr1[i];

		int st, end;
		while (true) {
			if (arr1.size() == 2) {
				int sec = arr1.back();
				int fir = arr1.front();
				if (fir > sec)
					cout << "Case #" << k << ": " << "Alice\n";
				else
					cout << "Case #" << k << ": " << "Bob\n";
				break;
			}
			st = 0;
			end = arr1.size() - 1;
			while (st <= end) {
				arr2.push_back(arr1[st] + arr1[end]);
				st++;
				end--;
			}
			arr1.clear();

			if (arr2.size() == 2) {
				int sec = arr2.back();
				int fir = arr2.front();
				if (fir > sec)
					cout << "Case #" << k << ": " << "Alice\n";
				else
					cout << "Case #" << k << ": " << "Bob\n";
				break;
			}
			st = 0;
			end = arr2.size() - 1;
			while (st <= end) {
				arr1.push_back(arr2[st] + arr2[end]);
				st++;
				end--;
			}
			arr2.clear();
		}
	}
	return 0;
}