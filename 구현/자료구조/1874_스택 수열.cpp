#include <iostream>
#include <stack>
#include <queue>
using namespace std;


int main() {
	int n, num = 1, in, flag = 0;
	string res;
	stack<int>s;
	queue<int>q;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		q.push(in);
	}
	for (int i = 1; i <= q.front(); i++) {
		s.push(num++);
		res += '+';
	}
	res += '-';
	q.pop();
	s.pop();

	while (1) {
		if (q.empty() == 1) break;
		if (s.empty() == 1 || q.front() > s.top()) {
			s.push(num++);
			res += '+';
		}
		else if (q.front() == s.top()) {
			res += '-';
			q.pop();
			s.pop();
		}
		else if (q.front() < s.top()) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) printf("NO");
	else {
		for (int i = 0; i < res.size(); i++) {
			printf("%c\n", res[i]);
		}
	}
}