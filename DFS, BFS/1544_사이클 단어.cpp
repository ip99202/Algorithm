#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>v;
vector<int>visited;
string arr[51];
queue<string>q;
int n, cnt;

void dfs(int now) {
	visited[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!visited[next])
			dfs(next);
	}
}

void compare(int n1, int n2) {
	int i, p, flag = 0;
	int temp = arr[n1].size();
	if (temp == arr[n2].size()) {
		for (int i = 0; i < temp; i++) {
			string word;
			word = arr[n2][0];
			arr[n2].erase(0, 1);
			arr[n2].append(word);
			if (arr[n1].compare(arr[n2]) == 0)
				flag = 1;
		}

		if (flag == 1) {
			arr[n2].clear();
			v[n1].push_back(n2);
			v[n2].push_back(n1);
			return;
		}
	}
	else
		return;
}

int main() {
	cin >> n;
	v.resize(n + 2);
	visited.resize(n + 2);
	for (int j = 0; j < n; j++) {
		cin >> arr[j];
	}

	for (int j = 0; j < n; j++)
		for (int i = 0; i < n; i++) {
			if (arr[i].size() == 0 || arr[j].size() == 0 || i == j)
				continue;
			compare(j, i);
		}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
}
