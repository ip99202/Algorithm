#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>P;
vector<int>h;
int res;

int main() {
	int m, n, l;
	scanf("%d%d%d", &m, &n, &l);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		h.push_back(x);
	}
	sort(h.begin(), h.end());

	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (y > l)
			continue;
		int min = x + y - l;
		int max = x - y + l;
		int L = 0;
		int R = h.size() - 1;
		while (L <= R) {
			int mid = (L + R) / 2;
			if (min <= h[mid] && max >= h[mid]) {
				res++;
				break;
			}
			if (min > h[mid])
				L = mid + 1;
			else if (max < h[mid])
				R = mid - 1;
		}
	}
	printf("%d", res);
}