#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, res = 0;
	cin >> n >> m;
	vector<vector<int>>party(m);

	int cnt; cin >> cnt;
	vector<int>tperson(cnt);

	for (int i = 0; i < cnt; i++)
		cin >> tperson[i];
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		for (int j = 0; j < num; j++) {
			int temp; cin >> temp;
			party[i].push_back(temp);
		}
	}

	for (int h = 0; h < n; h++) {
		for (int i = 0; i < m; i++) {
			vector<int>pushperson;
			bool flag = false;
			for (int j = 0; j < party[i].size(); j++) {
				pushperson.push_back(party[i][j]);
				for (int k = 0; k < tperson.size(); k++) {
					if (party[i][j] == tperson[k])
						flag = true;
				}
			}
			if (flag) {
				while (pushperson.size()) {
					tperson.push_back(pushperson.back());
					pushperson.pop_back();
				}
			}
			else {
				while (pushperson.size())
					pushperson.pop_back();
			}
		}
	}
	for (int i = 0; i < m; i++) {
		bool flag = false;
		for (int j = 0; j < party[i].size(); j++) {
			for (int k = 0; k < tperson.size(); k++) {
				if (party[i][j] == tperson[k])
					flag = true;
			}
		}
		if (!flag)
			res++;
	}
	cout << res;
	return 0;
}