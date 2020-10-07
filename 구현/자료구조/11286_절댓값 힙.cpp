#include<iostream>
#include<queue>
#include<functional>
#include<math.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>>q1;//양수
priority_queue<int, vector<int>, less<int>>q2;//음수

int main() {
	int n, num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num == 0) {
			if (q1.empty() == 1 && q2.empty() == 1)
				printf("0\n");
			else if (q1.empty() == 1) {
				printf("%d\n", q2.top());
				q2.pop();
			}
			else if (q2.empty() == 1) {
				printf("%d\n", q1.top());
				q1.pop();
			}
			else {
				if (q1.top() > abs(q2.top())) {
					printf("%d\n", q2.top());
					q2.pop();
				}
				else if (q1.top() < abs(q2.top())) {
					printf("%d\n", q1.top());
					q1.pop();
				}
				else if (q1.top() == abs(q2.top())) {
					printf("%d\n", q2.top());
					q2.pop();
				}
			}
		}
		else {
			if (num > 0)
				q1.push(num);
			else
				q2.push(num);
		}

	}

}