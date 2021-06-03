#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
typedef pair<int, bool>P;
int song[51][101];
vector<P>lis[51];

int main() {
	int n, e;
	scanf("%d%d", &n, &e);
	for (int day = 1; day <= e; day++) {
		int k;
		scanf("%d", &k);
		vector<int>temp;
		for (int j = 0; j < k; j++) {
			int t;
			scanf("%d", &t);
			song[day][t] = 1;
			temp.push_back(t);
		}
		if (!song[day][1]) {
			for (int i = 0; i < temp.size(); i++) {
				int peo = temp[i];
				for (int j = 1; j < day; j++) {
					if (song[j][peo] == 0) {
						for (int k = 0; k < temp.size(); k++) {
							if (song[j][temp[k]] == 1)
								song[j][peo] = 1;
						}
					}
				}
			}
		}
	}
	printf("1\n");
	for (int i = 2; i <= n; i++) {
		bool flag = false;
		for (int j = 1; j <= e; j++) {
			if (song[j][i] == 0 && song[j][1] == 1)
				flag = true;
		}
		if(!flag)
		printf("%d\n", i);
	}
}