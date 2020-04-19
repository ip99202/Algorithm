#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<deque>
#include<queue>
#include<cstring>
using namespace std;
vector<deque<int>>gear;
vector<vector<int>>cnt;// 몇번 톱니바퀴가 어느방향으로 몇번 돌아야하는지 저장
int res;

void check(int n, int y, int way) {// way==1 오른쪽방향
	int nn = n;
	while (true) {
		if (way == 1) {
			if (nn == 4) return;
			if (gear[nn][2] != gear[nn + 1][6]) {
				if (y == 1) y = -1;
				else y = 1;
				cnt[nn + 1].push_back(y);
			}
			else
				return;
		}
		else {
			if (nn == 1) return;
			if (gear[nn][6] != gear[nn - 1][2]) {
				if (y == 1) y = -1;
				else y = 1;
				cnt[nn - 1].push_back(y);
			}
			else
				return;
		}
		if (way == 1)
			nn += 1;
		else
			nn -= 1;
	}
}

void rotate() {
	for (int i = 1; i <= 4; i++) {
		while (!cnt[i].empty()) {
			if (cnt[i].front() == -1) {// 앞에서 빼서 뒤로 넣음
				int temp = gear[i].front();
				gear[i].pop_front();
				gear[i].push_back(temp);
			}
			else {
				int temp = gear[i].back();
				gear[i].pop_back();
				gear[i].push_front(temp);
			}
			cnt[i].pop_back();
		}
	}
}

int main() {
	gear.resize(5);
	for (int i = 1; i <= 4; i++)
		for (int j = 0; j < 8; j++) {
			int x;
			scanf("%1d", &x);
			gear[i].push_back(x);
		}
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		cnt.resize(6);
		int n, y;
		cin >> n >> y;
		cnt[n].push_back(y);
		check(n, y, 1);
		check(n, y, -1);
		rotate();
		cnt.clear();
	}
	for (int i = 1; i <= 4; i++) {// 점수계산
		if (gear[i][0] == 1)
			res += pow(2, i - 1);
	}
	printf("%d", res);
	return 0;
}