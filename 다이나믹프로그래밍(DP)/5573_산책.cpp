#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>P;
P arr[1001][1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int h, w, n;
	cin >> h >> w >> n;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j].first;
			if (i == 0 && j == 0) {
				arr[i][j].second = n - 1;
				arr[i][j + 1].second += arr[i][j].second / 2;
				arr[i + 1][j].second += arr[i][j].second / 2;
				if (arr[i][j].second % 2) {
					if (arr[i][j].first)
						arr[i][j + 1].second++;
					else
						arr[i + 1][j].second++;
				}
			}
			else if (i == h || j == w) {
				arr[i][j].second = 0;
				continue;
			}
			else {
				if (arr[i][j].second) {
					arr[i][j + 1].second += arr[i][j].second / 2;
					arr[i + 1][j].second += arr[i][j].second / 2;
					if (arr[i][j].second % 2) {
						if (arr[i][j].first)
							arr[i][j + 1].second++;
						else
							arr[i + 1][j].second++;
					}
				}
			}
		}
	}
	int x = 0, y = 0;
	while (true) {
		if (x == h || y == w) {
			cout << x + 1 << ' ' << y + 1;
			break;
		}
		if ((arr[x][y].second + arr[x][y].first) % 2)
			y++;
		else
			x++;
	}
	return 0;
}