#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string>
#include<cstring>
using namespace std;
char arr[105][105];
int check[105][105];
typedef pair<int, pair<int, int>>P;
vector<P>cross;
bool flag;

void go(int i, int j) {
	int l = i, r = i, u = j, d = j, cnt = 0;
	while (true) {
		l--;
		r++;
		u++;
		d--;
		if (arr[l][j] == '*' && arr[r][j] == '*' && arr[i][u] == '*' && arr[i][d] == '*') {
			cnt++;
			cross.push_back({ cnt,{i,j} });
		}
		else
			break;
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '*') {
				flag = true;
				if (arr[i][j + 1] == '.' || j + 1 > m)
					flag = false;
				if (arr[i][j - 1] == '.' || j - 1 < 0)
					flag = false;
				if (arr[i - 1][j] == '.' || i - 1 < 0)
					flag = false;
				if (arr[i + 1][j] == '.' || i + 1 > n)
					flag = false;
				if (flag == true) {
					go(i, j);
				}
			}
		}
	}
	if (cross.size() == 0) {
		printf("-1");
		return 0;
	}
	else {
		for (int k = 0; k < cross.size(); k++) {
			int x = cross[k].second.first;
			int y = cross[k].second.second;
			for (int i = 0; i <= cross[k].first; i++)
				if (y + i <= m)
					arr[x][y + i] = '.';
			for (int i = 0; i <= cross[k].first; i++)
				if (y - i >= 0)
					arr[x][y - i] = '.';
			for (int i = 0; i <= cross[k].first; i++)
				if (x + i <= n)
					arr[x + i][y] = '.';
			for (int i = 0; i <= cross[k].first; i++)
				if (x - i >= 0)
					arr[x - i][y] = '.';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '*') {
					printf("-1");
					return 0;
				}
			}
		}
	}
	printf("%d\n", cross.size());
	for (int i = 0; i < cross.size(); i++)
		printf("%d %d %d\n", cross[i].second.first + 1, cross[i].second.second + 1, cross[i].first);
}