#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cstring>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<vector<int>>v;
		vector<int>res;
		v.resize(3);
		int cnt = 0;
		for (int k = 0; k < 3; k++) {
			int x;
			cin >> x;
			for (int i = 0; i < x; i++) {
				int a;
				cin >> a;
				v[k].push_back(a);
			}
		}
		for (int i = 0; i < v[0].size(); i++) {
			for (int j = 0; j < v[1].size(); j++) {
				for (int k = 0; k < v[2].size(); k++) {
					int sum = v[0][i] + v[1][j] + v[2][k];
					int temp = v[0][i] + v[1][j] + v[2][k];
					bool flag = false;
					while (true) {
						if (sum % 10 == 5 || sum % 10 == 8)
							flag = true;
						else {
							flag = false;
							break;
						}
						sum /= 10;
						if (sum <= 0)
							break;
					}
					if (flag == true)
						res.push_back(temp);
				}
			}
		}
		if (res.empty()) {
			cout << 0 << '\n';
			continue;
		}
		sort(res.begin(), res.end());
		int temp = res[0];
		cnt = 1;
		for (int i = 1; i < res.size(); i++) {
			if (temp == res[i])
				continue;
			else {
				cnt++;
				temp = res[i];
			}
		}
		cout << cnt << '\n';
	}
}