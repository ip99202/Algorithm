#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main() {
	int n;
	char arr[51] = { 0, };
	int cnt = 0;
	cin >> n;
	for (int j = 0; j < n; j++) {
		stack<int>st;
		cin >> arr;
		cnt = strlen(arr);
		for (int i = 0; i < cnt; i++) {
			if (arr[i] == '(') st.push(1);
			if (arr[i] == ')') {
				if (st.empty() == 1) {
					printf("NO\n");
					break;
				}
				else if (st.top() == 1) {
					st.pop();
				}
			}
			if (i == cnt - 1) {
				if (st.empty() == 1) printf("YES\n");
				else if (st.empty() == 0) printf("NO\n");
			}
		}
		st.empty();
		cnt = 0;
	}
}