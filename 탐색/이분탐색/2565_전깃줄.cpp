#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>    
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
vector<P> arr;
vector<int>v;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		arr.push_back(P(x, y));
	}
	sort(arr.begin(), arr.end());
	v.push_back(arr[0].second);
	for (int i = 1; i < n; i++) {
		if (v.back() < arr[i].second) {
			v.push_back(arr[i].second);
		}
		else {
			int it = lower_bound(v.begin(), v.end(), arr[i].second) - v.begin();
			v[it] = arr[i].second;
		}
	}
	printf("%d", n - v.size());
}