#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>    
#define INF 999999999
using namespace std;
vector<int> v, arr;
int res;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		arr.push_back(x);
	}

	v.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
			res++;
		}
		else {
			int it = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[it] = arr[i];
		}
	}
	printf("%d", n - (res + 1));
}