#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, char>P;
typedef pair<char, int>PP;
vector<P>arr;
vector<PP>res;

int main() {
	int x, n;
	scanf("%d%d", &x, &n);
	for (int i = 0; i < n; i++) {
		char a;
		int b;
		getchar();
		scanf("%c%d", &a, &b);
		if (b < x * 0.05)
			continue;
		res.push_back(P(a, 0));
		for (int i = 1; i <= 14; i++) {
			arr.push_back(P(b / i, a));
		}
	}
	sort(arr.begin(), arr.end(), greater<P>());
	for (int i = 0; i < 14; i++) {
		char name = arr[i].second;
		for (int i = 0; i < res.size(); i++) {
			if (name == res[i].first)
				res[i].second++;
		}
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		printf("%c %d\n", res[i].first, res[i].second);
	}
}