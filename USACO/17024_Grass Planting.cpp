#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v[100001];
int indegree[100001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b); 
		v[b].push_back(a);
		indegree[b]++;
		indegree[a]++;
	}
	sort(indegree, indegree + 100001);
	printf("%d", indegree[100000] + 1);
}