#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
char temp[100001];
int res;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		stack<char>st;
		scanf("%s", temp);
		string arr = temp;
		int len = arr.length();
		for (int i = 0; i < len; i++) {
			if (st.size() > 0) {
				if (st.top() == arr[i]) {
					st.pop();
					continue;
				}
			}
			st.push(arr[i]);
		}
		if (st.empty() == true)
			res++;
		memset(temp, 0, 100001);
	}
	printf("%d", res);
}