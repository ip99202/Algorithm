#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int>res;

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

void kmp(string parent, string pattern) {
	vector<int>table = make_table(pattern);
	int parent_size = parent.size();
	int pattern_size = pattern.size();
	int j = 0;
	for (int i = 0; i < parent_size; i++) {
		while (j > 0 && parent[i] != pattern[j])
			j = table[j - 1];
		if (parent[i] == pattern[j]) {
			if (j == pattern_size - 1) {
				res.push_back(i - pattern_size + 1);
				j = table[j];
			}
			else
				j++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, s;
	string parent, pattern;
	cin >> n >> s >> parent;
	pattern = "IOI";
	for (int i = 0; i < n - 1; i++)
		pattern += "OI";
	kmp(parent, pattern);
	cout << res.size();
}