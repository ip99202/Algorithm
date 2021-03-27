#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int>bi;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		while (n > 0) {
			bi.push_back(n % 2);
			n /= 2;
		}
		for (int i = 0; i < bi.size(); i++) {
			if (bi[i] == 1)
				printf("%d ", i);
		}
		printf("\n");
		bi.clear();
	}
}