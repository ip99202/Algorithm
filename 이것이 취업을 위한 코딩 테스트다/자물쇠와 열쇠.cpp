#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int key_len = key.size(), lock_len = lock.size();
	for (int rot = 1; rot <= 4; rot++) {
		vector<vector<int>>tmp;
		tmp.resize(key_len);
		for (int i = 0; i < key_len; i++) {
			for (int j = 0; j < key_len; j++) {
				if (rot % 2 == 0) {
					if (rot == 2) {
						tmp[j].push_back(key[key_len - i - 1][j]);
					}
					// 2,0 | 1,0 | 0,0
					// 2,1 | 1,1 | 0,1
					// 2,2 | 1,2 | 0,2
					else {
						tmp[j].push_back(key[i][key_len - j - 1]);
					}
					// 0,2 | 1,2 | 2,2 
					// 0,1 | 1,1 | 2,1
					// 0,0 | 1,0 | 2,0
				}
				else {
					if (rot == 1) {
						tmp[i].push_back(key[i][j]);
					}
					// 0,0 | 0,1 | 0,2 
					// 1,0 | 1,1 | 1,2
					else {
						tmp[i].push_back(key[key_len - i - 1][key_len - j - 1]);
					}
					// 2,2 | 2,1 | 2,0
					// 1,2 | 1,1 | 1,0 
				}
			}
		}
		for (int row = -key_len + 1; row < lock_len; row++) {
			for (int col = -key_len + 1; col < lock_len; col++) {
				vector<vector<int>>arr;
				arr.assign(lock.begin(), lock.end());
				for (int i = 0; i < key_len; i++) {
					for (int j = 0; j < key_len; j++) {
						if (row + i >= 0 && col + j >= 0 && row + i < lock_len && col + j < lock_len) {
							arr[row + i][col + j] += tmp[i][j];
						}
					}
				}
				bool res = true;
				for (int i = 0; i < lock_len; i++) {
					for (int j = 0; j < lock_len; j++) {
						if (arr[i][j] == 0 || arr[i][j] > 1)
							res = false;
					}
				}
				if (res)
					return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<vector<int>> a = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
	vector<vector<int>> b = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
	if (solution(a, b))
		cout << "true";
	else cout << "false";
	return 0;
}