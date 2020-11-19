#include<iostream> 
#include<vector> 
#include<queue> 
#include<algorithm>
using namespace std;

int n;
vector<vector<int> > v;
int parent[100001];
bool visited[100001];

void input() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}

void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int nx : v[x]) {
			if (!visited[nx]) {
				parent[nx] = x;
				visited[nx] = true;
				q.push(nx);
			}
		}
	}
}

void pr() {
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	input();
	bfs();
	pr();
	return 0;
}
