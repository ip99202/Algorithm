#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<deque>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
typedef pair<int, int>P;
// 비교대상보다 멀면서 비싼곳
int main() {
	int n, res = 0;
	vector<P>v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back(P(x, y));
	}
	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (v[i].first > v[j].first) {
				if (v[i].second >= v[j].second) {
					flag = true;
				}
			}
			else if (v[i].second > v[j].second) {
				if (v[i].first >= v[j].first) {
					flag = true;
				}
			}
		}
		if (flag == false)
			res++;
	}
	printf("%d", res);
}