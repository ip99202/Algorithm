#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef pair<int, int> P;
vector<P> v[1001];

int main() {
	int i, n, l, d, r, g, time, now = 0;
	scanf("%d %d", &n, &l);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &d, &r, &g);
		v[d].push_back({ r, r + g });
	}
	for (time = 0; now != l; time++) {
		if (v[now].empty())
			now++;
		else {
			if (time % v[now][0].second > v[now][0].first || time % v[now][0].second == 0)
				now++;
			else
				continue;
		}
	}
	printf("%d\n", time - 1);
}