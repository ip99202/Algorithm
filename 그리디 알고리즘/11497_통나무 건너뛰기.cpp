#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int>wood;
vector<int>w1, w2;

int main() {
	int n, j = 0, k = 0;
	int max = 0;
	scanf("%d", &n);
	while (n--) {
		int l = 0;
		wood.resize(l + 1);
		scanf("%d", &l);
		for (int i = 0; i < l; i++) {
			int x;
			scanf("%d", &x);
			wood.push_back(x);
		}
		sort(wood.begin(), wood.end());
		for (int i = 1; i <= l; i++) {
			if (i % 2 == 0) {
				w1.push_back(wood[i]);
				k++;
				if (k > 1) {
					if (w1[k - 1] - w1[k - 2] > max)
						max = w1[k - 1] - w1[k - 2];
				}
			}
			if (i % 2 == 1) {
				w2.push_back(wood[i]);
				j++;
				if (j > 1) {
					if (w2[j - 1] - w2[j - 2] > max)
						max = w2[j - 1] - w2[j - 2];
				}
			}

		}
		if (abs(w1[0] - w2[0]) > max)
			max = abs(w1[0] - w2[0]);
		if (abs(w1.back() - w2.back()) > max)
			max = abs(w1.back() - w2.back());
		printf("%d\n", max);
		wood.clear();
		w1.clear();
		w2.clear();
		k = 0;
		j = 0;
		max = 0;
	}
}