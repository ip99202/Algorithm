#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int res;
int num[101][3];
int cup[4];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &num[i][0], &num[i][1], &num[i][2]);
	for (int i = 1; i <= 3; i++) {
		int temp = 0;
		fill(cup, cup + 4, 0);
		cup[i] = 1;
		for (int j = 0; j < n; j++) {
			int a, b, g;
			a = num[j][0];
			b = num[j][1];
			g = num[j][2];
			swap(cup[a], cup[b]);
			if (cup[g] == 1)
				temp++;
		}
		res = max(res, temp);
	}
	printf("%d", res);
}