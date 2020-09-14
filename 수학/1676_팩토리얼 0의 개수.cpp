#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>	
#define INF 999999999
using namespace std;
int num[10];

int main() {
	int n, res = 0;
	scanf("%d", &n);
	for (int j = 1; j <= n; j++) {
		int i = j;
		if (i % 2 == 0) {
			num[2]++;
			i /= 2;
			while (true) {
				if (i % 2 == 0) {
					num[2]++;
					i = i / 2;
				}
				else
					break;
			}
		}
		if (i % 5 == 0) {
			num[5]++;
			i /= 5;
			while (true) {
				if (i % 5 == 0) {
					num[5]++;
					i = i / 5;
				}
				else
					break;
			}
		}
		if (i % 10 == 0) {
			num[10]++;
			i /= 10;
			while (true) {
				if (i % 10 == 0) {
					num[10]++;
					i = i / 10;
				}
				else
					break;
			}
		}
	}
	int temp = min(num[2], num[5]);
	num[10] += temp;
	printf("%d", num[10]);
}