#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<math.h>
using namespace std;
priority_queue<int, vector<int>, less<int>>maxx;
priority_queue<int, vector<int>, greater<int>>minn;
/*
중간 값 구하기 알고리즘
1. 최대 힙의 크기는 최소 힙의 크기와 같거나, 하나 더 크다.
2. 최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.
이때 알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap해준다.
*/

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (maxx.size() == 0)
			maxx.push(x);
		else if (maxx.size() == minn.size())
			maxx.push(x);
		else
			minn.push(x);
		if (!maxx.empty() && !minn.empty() && maxx.top() > minn.top()) {
			int a = maxx.top();
			int b = minn.top();
			maxx.pop();
			minn.pop();
			maxx.push(b);
			minn.push(a);
		}
		printf("%d\n", maxx.top());
	}
}