#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
typedef pair<int, int>P;
P front[101];
P back[101];
int cnt, ans;

int main() {
	int n, st = 9999, end = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		front[i] = { a,c };
		back[i] = { b,c };
		st = min(front[i].first, st);
		end = max(back[i].first, end);
	}
	sort(front, front + n + 1);
	sort(back, back + n + 1);
	for (int time = st; time <= end; time++) {
		for (int i = 1; i <= n; i++) {
			if (front[i].first == time)
				cnt += front[i].second;
			if (back[i].first == time)
				cnt -= back[i].second;
		}
		ans = max(cnt, ans);
	}
	printf("%d", ans);
}