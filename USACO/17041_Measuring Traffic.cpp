#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#define INF 999999999
using namespace std;
typedef pair<int, int>p;
typedef pair<string, p>pp;
vector<pp>arr;
p front, back;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		arr.push_back({ s,{a,b} });
	}
	int mi = -1, ma = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i].first == "none") {
			if (mi == -1 && ma == -1) {
				mi = arr[i].second.first;
				ma = arr[i].second.second;
			}
			if (mi < arr[i].second.first)
				mi = arr[i].second.first;
			if (ma > arr[i].second.second)
				ma = arr[i].second.second;
		}
		else if (arr[i].first == "on") {
			if (mi == -1 && ma == -1)
				continue;
			mi += arr[i].second.first;
			ma += arr[i].second.second;
		}
		else if (arr[i].first == "off") {
			if (mi == -1 && ma == -1)
				continue;
			mi -= arr[i].second.second;
			ma -= arr[i].second.first;
		}
	}
	if (mi < 0)
		mi = 0;
	back = p(mi, ma);

	mi = -1, ma = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i].first == "none") {
			if (mi == -1 && ma == -1) {
				mi = arr[i].second.first;
				ma = arr[i].second.second;
			}
			if (mi < arr[i].second.first)
				mi = arr[i].second.first;
			if (ma > arr[i].second.second)
				ma = arr[i].second.second;
		}
		else if (arr[i].first == "on") {
			if (mi == -1 && ma == -1)
				continue;
			mi -= arr[i].second.second;
			ma -= arr[i].second.first;
		}
		else if (arr[i].first == "off") {
			if (mi == -1 && ma == -1)
				continue;
			mi += arr[i].second.first;
			ma += arr[i].second.second;
		}
	}
	if (mi < 0)
		mi = 0;
	front = p(mi, ma);
	printf("%d %d\n%d %d", front.first, front.second, back.first, back.second);
}