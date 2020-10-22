#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	set<string>arr;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (b == "enter")
			arr.insert(a);
		else
			arr.erase(a);
	}
	for (auto i = arr.rbegin(); i != arr.rend(); i++)
		cout << *i << "\n";
}