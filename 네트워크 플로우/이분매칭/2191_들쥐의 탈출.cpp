#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<math.h>
using namespace std;
typedef pair<double, double>P;
vector<int>arr[100001];
vector<P>mouse;
vector<P>cave;
int visited[100001];
bool match[100001];
int n, m, cnt;
double s, v;

bool dfs(int x) {
	if (match[x]) return false;
	match[x] = 1;
	for (int i = 0; i < arr[x].size(); i++) {
		int temp = arr[x][i];
		if (!visited[temp] || dfs(visited[temp])) {
			visited[temp] = x;
			return true;
		}
	}
	return false;
}

double dist(P x, P y) {
	return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

int main() {
	scanf("%d%d%lf%lf", &n, &m, &s, &v);
	mouse.push_back(P(0, 0));
	cave.push_back(P(0, 0));
	for (int i = 0; i < n; i++) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		mouse.push_back(P(x, y));
	}
	for (int i = 0; i < m; i++) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		cave.push_back(P(x, y));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			double way = dist(mouse[i], cave[j]);
			if (s * v >= way)
				arr[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		fill(match, match + 100001, false);
		if (dfs(i))
			cnt++;
	}
	printf("%d", n - cnt);
}