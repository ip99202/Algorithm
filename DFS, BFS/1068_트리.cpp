#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>	
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
vector<vector<int>>tree;
queue<int>q;
int input[51], del;

int main() {
	int n, x, res = 0;
	int root;
	scanf("%d", &n);
	tree.resize(n + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		input[i] = x;
		if (x == -1)
			del = i;
	}
	scanf("%d", &x);
	if (x == del) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (i == x || input[i] == x)
			continue;
		if (input[i] == -1) {
			q.push(i);
			continue;
		}
		tree[input[i]].push_back(i);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			if (tree[next].size() == 0)
				res++;
			else
				q.push(next);
		}
	}
	if (res == 0)
		res++;
	printf("%d", res);
}