#include<iostream>
#include<vector>
#include<deque>
using namespace std;
deque<int>de;

int main() {
	int t, n = 1;
	cin >> t;
	while (t--)	{
		char x;
		cin >> x;
		if (x == 'A') {
			char y;
			cin >> y;
			if (y == 'L')
				de.push_front(n);
			else
				de.push_back(n);
			n++;
		}
		else {
			char y;
			cin >> y;
			int c;
			cin >> c;
			for (int i = 0; i < c; i++) {
				if (y == 'L')
					de.pop_front();
				else
					de.pop_back();
			}
		}
	}
	int cnt = de.size();
	for (int i = 0; i < cnt; i++)
		cout << de[i] << "\n";
}