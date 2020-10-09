#include <iostream> 
#include <queue>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	queue<int>q;
	for (int i = 1; i <= n; i++) q.push(i);
	printf("<");
	while (!q.empty()) {
		if (q.size() == 1) {
			printf("%d>", q.front());
			q.pop();
			break;
		}
		for (int i = 1; i < m; i++) {
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	printf("\n");
}