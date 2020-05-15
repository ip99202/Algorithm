#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>	
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
priority_queue<P, vector<P>, greater<P>>pq;
int arr[51][51], res[51];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			arr[i][j] = INF;
		}
	}
	while (true) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == -1 && y == -1)
			break;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	int temp = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			res[i] = max(res[i], arr[i][j]);
		}
		temp = min(res[i], temp);
	}
	int c = 0;
	for (int i = 1; i <= n; i++)
		if (temp == res[i])
			c++;
	printf("%d %d\n", temp, c);
	for (int i = 1; i <= n; i++)
		if (temp == res[i])printf("%d ", i);
}