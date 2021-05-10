#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<deque>
#include<limits.h>
#include<sstream>
using namespace std;
typedef pair<int, int>P;
typedef pair<P, int>PP;

struct customer {
	int time, level, id, flag;
	//flag 1-활성화 0-스택에 들어가있는 -1-이미 탑승
};
struct compare {
	bool operator()(customer t, customer u) {
		if (t.level == u.level && t.time == u.time)
			return t.id > u.id;
		if (t.level == u.level)
			return t.time > u.time;
		return t.level > u.level;
	}
};
bool cmp(customer a, customer b) {
	if (a.time == b.time)
		return a.level < b.level;
	return a.time < b.time;
}

vector<int> solution(vector<int> t, vector<int> r) {
	vector<int> answer;
	deque<customer>arr;
	int len = t.size();
	int max_t = 0, min_t = INT_MAX;
	for (int i = 0; i < len; i++) {
		arr.push_back({ t[i],r[i],i,1 });
		max_t = max(t[i], max_t);
		min_t = min(t[i], min_t);
	}
	sort(arr.begin(), arr.end(), cmp);

	int time = min_t;
	priority_queue<customer, vector<customer>, compare>pq;
	for (int t = min_t; t < 20000; t++) {
		for (int i = 0; i < len; i++) {
			if (arr[i].time <= t && arr[i].flag != -1) {
				pq.push(arr[i]);
				arr[i].flag = -1;
			}
		}
		if (!pq.empty()) {
			answer.push_back(pq.top().id);
			pq.pop();
		}
	}

	return answer;
}