#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int check[2005][2005];
int sum, n;
string s;
int main() {
	scanf("%d", &n);
	cin >> s;
	int x = 1002, y = 1002;
	check[1002][1002] = 1;
	sum = 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'S') {
			if (check[x][y - 1] == 0) {
				sum++;
				check[x][y - 1]++;
			}
			y--;
		}
		else if (s[i] == 'E') {
			if (check[x + 1][y] == 0) {
				sum++;
				check[x + 1][y]++;
			}
			x++;
		}
		else if (s[i] == 'N') {
			if (check[x][y + 1] == 0) {
				sum++;
				check[x][y + 1]++;
			}
			y++;
		}
		else if (s[i] == 'W') {
			if (check[x - 1][y] == 0) {
				sum++;
				check[x - 1][y]++;
			}
			x--;
		}
	}
	printf("%d", sum);


	return 0;
}