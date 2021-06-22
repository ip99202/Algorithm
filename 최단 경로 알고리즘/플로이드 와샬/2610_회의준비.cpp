#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000000
using namespace std;
int main(void)
{
	int n, m, link[101][101] = { 0, }, x, y;
	bool check[101];
	int cnt = 0, max[101] = { 0, };
	vector<int> arr;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (i ^ j)
				link[i][j] = INF;
		check[i] = false;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		link[x][y] = link[y][x] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (link[i][k] + link[k][j] < link[i][j])
					link[i][j] = link[i][k] + link[k][j];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (link[i][j]<INF && link[i][j]>max[i])
				max[i] = link[i][j];
	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			int idx = i;
			for (int j = 1; j <= n; j++)
			{
				if (link[i][j] < INF)
				{
					check[j] = true;
					if (max[idx] > max[j])
						idx = j;
				}
			}
			arr.push_back(idx);
		}
	}
	sort(arr.begin(), arr.end());
	cout << arr.size() << "\n";
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << "\n";
}