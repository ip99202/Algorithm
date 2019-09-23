#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>P;
vector<int>arr1;
vector<int>arr2;
int order[101], temp[101];

int main() {
	int n;
	scanf("%d", &n);
	arr1.resize(n + 1);
	arr2.resize(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &temp[i]);
	for (int i = 1; i <= n; i++)
		order[temp[i]] = i;
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr1[i]);
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			if (i % 2 == 0) {
				arr2[order[j]] = arr1[j];
			}
			else if (i % 2 == 1) {
				arr1[order[j]] = arr2[j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", arr2[i]);
	}
}