#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int pl[1001];
int mi[1001];
int first[11];
int second[11];
vector<int>ans;

int main() {
	ans.push_back(0);
	for (int i = 1; i <= 10; i++) scanf("%d", &first[i]);
	for (int i = 1; i <= 10; i++) scanf("%d", &second[i]);
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			for (int k = 0; k <= 10; k++) {
				for (int m = 0; m <= 10; m++) {
					int res = 0;
					res -= first[i];
					second[0] = first[i];
					res += second[j];
					first[0] = second[j];
					if (k == i) continue;
					res -= first[k];
					if (m == j) continue;
					res += second[m];
					if (res > 0) {
						if (pl[res] == 0) {
							pl[res] = 1;
							ans.push_back(res);
						}
					}
					else if (res < 0) {
						if (mi[-res] == 0) {
							mi[-res] = 1;
							ans.push_back(res);
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans.size());
}