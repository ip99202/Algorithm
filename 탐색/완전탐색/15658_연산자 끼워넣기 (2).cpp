#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
vector<int>arr;
int n, maxx = INT_MIN, minn = INT_MAX;

void calculate(int now, int sum, vector<int>& oper) {
	if (now == n - 1) {
		maxx = max(maxx, sum);
		minn = min(minn, sum);
		return;
	}
	if (now == 0)
		sum = arr[0];
	int num = arr[now + 1];
	if (oper[0] > 0) {
		oper[0]--;
		calculate(now += 1, sum + num, oper);
		oper[0]++;
		now--;
	}
	if (oper[1] > 0) {
		oper[1]--;
		calculate(now += 1, sum - num, oper);
		oper[1]++;
		now--;
	}
	if (oper[2] > 0) {
		oper[2]--;
		calculate(now += 1, sum * num, oper);
		oper[2]++;
		now--;
	}
	if (oper[3] > 0) {
		oper[3]--;
		calculate(now += 1, sum / num, oper);
		oper[3]++;
		now--;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	arr.resize(n);
	vector<int>oper(4);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	calculate(0, 0, oper);
	cout << maxx << "\n" << minn;
	return 0;
}