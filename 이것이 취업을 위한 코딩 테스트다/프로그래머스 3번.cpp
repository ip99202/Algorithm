#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<stack>
#include<string>
#include<deque>
#include<limits.h>
#include<sstream>
using namespace std;
typedef pair<int, int>P;
typedef pair<P, int>PP;

int go(int x, int y, vector<vector<int>>& arr, int p, int r) {
	int cnt = 0;
	int len = arr.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (i < x && j < y) {
				if (abs(i - x) + abs(j - y) <= r / 2) {
					if (arr[i][j] <= p)
						cnt++;
				}
				else if (abs(i - x) + abs(j - y) == r / 2 + 1) {
					if (arr[i][j] <= p / 2)
						cnt++;
				}
			}
			else if (i >= x && j >= y) {
				if (abs(i - x) + abs(j - y) <= r / 2 - 2) {
					if (arr[i][j] <= p)
						cnt++;
				}
				else if (abs(i - x) + abs(j - y) == r / 2 - 1) {
					if (arr[i][j] <= p / 2)
						cnt++;
				}
			}
			else {
				if (abs(i - x) + abs(j - y) <= r / 2 - 1) {
					if (arr[i][j] <= p)
						cnt++;
				}
				else if (abs(i - x) + abs(j - y) == r / 2) {
					if (arr[i][j] <= p / 2)
						cnt++;
				}
			}
		}
	}
	return cnt;
}

int solution(vector<vector<int>> maps, int p, int r) {
	int answer = 0;
	int len = maps.size();
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j <= len; j++) {
			answer = max(answer, go(i, j, maps, p, r));
		}
	}
	return answer;
}