#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
typedef pair<double, int>P;

vector<int> solution(int n, vector<int> stages) {
	vector<P>res;
	int len = stages.size();
	vector<int>check(len, 0);
	for (int i = 1; i <= n; i++) {
		int cnt = 0, total = 0;
		for (int j = 0; j < len; j++) {
			if (stages[j] >= i) {
				total++;
				if (stages[j] == i)
					cnt++;
			}
		}
		res.push_back({ (double)total / (double)cnt,i });
	}
	sort(res.begin(), res.end());
	vector<int> answer;
	for (int i = 0; i < n; i++)
		answer.push_back(res[i].second);
	return answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n = 5;
	vector<int>tmp = { 2, 1, 2, 6, 2, 4, 3, 3 };
	solution(n, tmp);
	return 0;
}