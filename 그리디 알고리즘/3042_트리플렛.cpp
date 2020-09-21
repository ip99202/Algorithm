#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct node {
	double x, y;
};

double cal(node a, node b) {
	return (b.y - a.y) / (b.x - a.x);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<node>arr;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char k; cin >> k;
			if (k != '.')
				arr.push_back({ (double)i,(double)j });
		}
	}

	int res = 0;
	int len = arr.size();
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			for (int k = j + 1; k < len; k++) {
				if (cal(arr[i], arr[j]) == cal(arr[i], arr[k])
					&& cal(arr[j], arr[k]) == cal(arr[i], arr[k]))
					res++;
			}
		}
	}
	cout << res;
	return 0;
}