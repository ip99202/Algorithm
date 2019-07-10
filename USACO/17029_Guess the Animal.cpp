#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>arr[101];
int cnt;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int cnt;
		cin >> name;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			string ch;
			cin >> ch;
			arr[i].push_back(ch);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int temp = 0;
			for (int k = 0; k < arr[i].size(); k++) {
				for (int l = 0; l < arr[j].size(); l++) {
					if (arr[i][k] == arr[j][l])
						temp++;
				}
			}
			cnt = max(temp, cnt);
		}
	}
	printf("%d", cnt + 1);
}