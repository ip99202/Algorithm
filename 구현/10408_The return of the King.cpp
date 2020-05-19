#include<iostream>
#include<vector>
using namespace std;
vector<int>v;

int main() {
	string arr;
	cin >> arr;
	for (int i = 0; i < arr.length(); i++) {
		v.push_back(arr[i] - '0');
		if (arr[i] == '0') {
			v.pop_back();
			v.pop_back();
			v.push_back(10);
		}
	}
	int n = v.size();
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += v[i];
	printf("%.2f", sum / n);
}

