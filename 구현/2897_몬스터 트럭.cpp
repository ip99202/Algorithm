#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
typedef pair<int, int>P;
int dx[] = { 0,0,1,1 };
int dy[] = { 0,1,0,1 };
char arr[101][101];
int res[6];

int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; i++)
		scanf("%s", &arr[i]);
	for (int i = 0; i < h - 1; i++) {
		for (int j = 0; j < w - 1; j++) {
			int cnt = 0;
			bool flag = false;
			for (int k = 0; k < 4; k++) {
				if (arr[i + dx[k]][j + dy[k]] == '#')
					flag = true;
				if (arr[i + dx[k]][j + dy[k]] == 'X')
					cnt++;
			}
			if (flag == true)
				continue;
			res[cnt]++;
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d\n", res[i]);
	}
}