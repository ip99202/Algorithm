#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
char order[20] = { 'a', 'b', 'k', 'd', 'e', 'g', 'h', 'i', 'l', 'm', 'n', 'z', 'o', 'p', 'r', 's', 't', 'u', 'w', 'y' };
//ng->z

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<string>arr;
	for (int k = 0; k < n; k++) {
		string input;
		string temp;
		cin >> input;
		int len = input.size();
		for (int i = 0; i < len; i++) {
			if (input[i] == 'n' && i != len - 1) {
				if (input[i + 1] == 'g') {
					temp += 'l';
					i++;
					continue;
				}
			}
			for (int j = 0; j < 20; j++) {
				if (input[i] == order[j]) {
					temp += (j + 'a');
					break;
				}
			}
		}
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	for (int k = 0; k < arr.size(); k++) {
		string temp;
		int len = arr[k].size();
		for (int i = 0; i < len; i++) {
			if (arr[k][i] == 'l') {
				temp += "ng";
				continue;
			}
			temp += (order[arr[k][i] - 'a']);
		}
		cout << temp << "\n";
	}
	return 0;
}