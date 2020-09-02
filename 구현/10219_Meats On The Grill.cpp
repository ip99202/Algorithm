#include <iostream>
using namespace std;

char grill[12][12];
int h, w;

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> h >> w;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++)
				cin >> grill[i][j];
		}

		for (int i = 1; i <= h; i++) {
			for (int j = w; j >= 1; j--)
				cout << grill[i][j];
			cout << '\n';
		}
	}
}
