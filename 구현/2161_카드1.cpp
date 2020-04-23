#include<iostream>
#include<queue>
using namespace std;
queue<int>q;
int here;

void play(int n) {
	while (q.empty() == 0) {
		here = q.front();
		cout << here << ' ';
		q.pop();
		here = q.front();
		q.pop();
		q.push(here);
		if (q.size() == 1) {
			cout << here;
			break;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push(i);
	play(n);
}