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
�߰� �� ���ϱ� �˰���
1. �ִ� ���� ũ��� �ּ� ���� ũ��� ���ų�, �ϳ� �� ũ��.
2. �ִ� ���� �ִ� ���Ҵ� �ּ� ���� �ּ� ���Һ��� �۰ų� ����.
�̶� �˰��� ���� �ʴٸ� �ִ� ��, �ּ� ���� ���� ���� ���� swap���ش�.
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