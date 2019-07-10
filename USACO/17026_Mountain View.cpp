#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>P;
vector<P>v;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back(P(-y, -x));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int x = -v[i].second;
		int y = -v[i].first;
		if (x == 0 && y == 0)
			continue;
		for (int j = i + 1; j < n; j++) {
			int nx = -v[j].second;
			int ny = -v[j].first;
			if (nx == 0 && ny == 0)
				continue;
			if (x > nx) {
				if (nx - x + y >= ny) {
					v[j].first = 0;
					v[j].second = 0;
				}
			}
			if (x < nx) {
				if (-nx + x + y >= ny) {
					v[j].first = 0;
					v[j].second = 0;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].first == 0 && v[i].second == 0)
			continue;
		cnt++;
	}
	printf("%d", cnt);
}