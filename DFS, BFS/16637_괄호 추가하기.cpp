#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<limits.h>
using namespace std;
bool visited[20];	
vector<int>num;
vector<char>oper(1);
vector<string>cal;
int res = INT_MIN;

void calculate() {
	int sum = stoi(cal[0]);
	for (int i = 1; i < cal.size(); i++) {
		if (cal[i] == "+")
			sum += stoi(cal[i + 1]);
		else if (cal[i] == "-")
			sum -= stoi(cal[i + 1]);
		else if (cal[i] == "*")
			sum *= stoi(cal[i + 1]);
		i++;
	}
	res = max(res, sum);
	cal.clear();
}

void order() {
	for (int i = 1; i <= num.size(); i++) {
		if (visited[i]) {
			int n1, n2;
			n1 = num[i - 1];
			n2 = num[i];
			int tmp;
			if (oper[i] == '+')
				tmp = n1 + n2;
			else if (oper[i] == '-')
				tmp = n1 - n2;
			else
				tmp = n1 * n2;
			cal.push_back(to_string(tmp));
			if (i == num.size() - 1) continue;
			string t = "";
			t += oper[i + 1];
			cal.push_back(t);
			i++;
		}
		else {
			cal.push_back(to_string(num[i - 1]));
			if (i == num.size()) continue;
			string t = "";
			t += oper[i];
			cal.push_back(t);
		}

	}
	calculate();
}

void chk() {
	for (int i = 2; i < num.size(); i++) {
		if (visited[i] && visited[i - 1])
			return;
	}
	order();
}

void dfs(int idx, int cnt, int max) {
	if (cnt == max) {
		chk();
		return;
	}
	for (int i = idx; i < oper.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(i, cnt + 1, max);
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char x; cin >> x;
		if (n == 1) {
			cout << x;
			return 0;
		}
		if (i % 2 == 1)
			oper.push_back(x);
		else
			num.push_back(x - '0');
	}
	int max;
	if (num.size() % 2 == 0)
		max = num.size() / 2;
	else
		max = num.size() / 2 + 1;
	for (int i = 1; i <= max; i++) 
		dfs(1, 0, i);
	cout << res;
	return 0;
}