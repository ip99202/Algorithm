#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
vector<int>cow;
int pass[101];
int cnt, n;

int next(int i) {
	if (i == 0)
		return i + 1;
	else if (i == n - 1)
		return i - 1;
	else {
		int le = cow[i] - cow[i - 1];
		int ri = cow[i + 1] - cow[i];
		if (le <= ri)
			return i - 1;
		else
			return i + 1;
	}
}

int main() {
	scanf("%d", &n);
	cow.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &cow[i]);
	sort(cow.begin(), cow.end());

	for (int i = 0; i < n; i++)
		pass[next(i)]++;
	for (int i = 0; i < n; i++) {
		if (!pass[i])
			cnt++;
		if (i < next(i) && next(next(i)) == i && pass[i] == 1
			&& pass[next(i)] == 1)
			cnt++;
	}
	printf("%d", cnt);
}