#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>P;

bool cmp(P a, P b) {
	return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
	int len = food_times.size();
	int div = k / len;
	int left = k % len;
	vector<P>arr;

	long long sum = 0;
	for (int i = 0; i < len; i++) {
		arr.push_back(P(food_times[i], i + 1));
		sum += food_times[i];
	}
	if (sum <= k)
		return -1;

	sort(arr.begin(), arr.end(), greater<P>());
	int minus = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (k - ((i + 1) * arr[i].first) <= 0)
			break;
		k -= ((i + 1) * arr[i].first);
		arr[i - 1].first -= (arr[i].first + minus);
		minus += arr[i].first;
		arr.pop_back();
	}
	sort(arr.begin(), arr.end(), cmp);
	int answer = arr[k % arr.size()].second;
	return answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int k = 1833;
	vector<int>arr = { 946, 314, 757, 322, 559, 647, 983, 482, 145 };
	//int k = 15;
	//vector<int>arr = { 4, 3, 5, 1, 3 };
	cout << solution(arr, k);
	return 0;
}