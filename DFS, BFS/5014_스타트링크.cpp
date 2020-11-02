#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<deque>
#include<queue>
#include<cstring>
using namespace std;
int f, s, g, u, d;
queue<int>q;
int visited[2000001];

int main() {
	cin >> f >> s >> g >> u >> d;
	q.push(s);
	if (s == g) {
		printf("0");
		return 0;
	}
	visited[s] = 1;
	int ud[2] = { u,-d };
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			int next = now + ud[i];
			if (next > f || next <= 0)
				continue;
			if (visited[next] == 0) {
				visited[next] = visited[now] + 1;
				q.push(next);
				if (next == g) {
					cout << visited[g] - 1;
					return 0;
				}
			}
		}
	}
	cout << "use the stairs";
}