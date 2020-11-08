#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> make_table(string arr) {
	int size = arr.size();
	vector<int>table(size, 0);
	int j = 0;
	for (int i = 1; i < size; i++) {
		while (j > 0 && arr[i] != arr[j])
			j = table[j - 1];
		if (arr[i] == arr[j])
			table[i] = ++j;
	}
	return table;
}

int main() {
	ios::sync_with_stdio(false);
	while (true) {
		string pattern;
		cin >> pattern;
		if (pattern == ".")
			break;
		int len = pattern.size();
		vector<int>arr = make_table(pattern);
		if (len % (len - arr[len - 1]) != 0)
			cout << 1 << "\n";
		else
			cout << len / (len - arr[len - 1]) << "\n";
	}
}