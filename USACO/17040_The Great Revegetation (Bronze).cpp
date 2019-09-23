#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
int arr[101][151];
vector<int>res;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a][i] = 1;
		arr[b][i] = 1;
	}
	res.push_back(1);
	for (int i = 2; i <= n; i++) {
		bool flag[6];
		fill(flag, flag + 6, false);
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1) {
				for (int k = i - 1; k > 0; k--) {
					if (arr[k][j] == 1) {
						flag[res[k - 1]] = true;
						break;
					}
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (flag[j] == false) {
				res.push_back(j);
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d", res[i]);
	}
}