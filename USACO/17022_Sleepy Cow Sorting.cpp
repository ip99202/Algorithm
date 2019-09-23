#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int>v, back;
queue<int>head, res;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	int i, temp;
	for (i = n - 1; i >= 0; i--) {
		if (i == n - 1) {
			temp = v[i];
		}
		else if (temp > v[i]) {
			temp = v[i];
		}
		else
			break;
	}
	i++;
	for (int j = 0; j < i; j++)
		head.push(v[j]);
	int ans = head.size();
	int k = 0;
	for (i; i < n; i++)
		back.push_back(v[i]);

	while (!head.empty()) {
		int now = head.front();
		head.pop();
		int p;
		auto pl = lower_bound(back.begin(), back.end(), now);
		if (pl != back.end())
			p = head.size() + (pl - back.begin());
		else p = head.size() + back.size();
		res.push(p);
		back.insert(pl, now);
	}

	printf("%d\n", ans);
	while (!res.empty()) {
		printf("%d ", res.front());
		res.pop();
	}
}