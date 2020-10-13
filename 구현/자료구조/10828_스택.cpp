#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main() {
	stack<int>s;
	int n, num;
	char arr[10];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr;
		if (arr[0] == 'p') {
			if (arr[1] == 'u') {//push
				cin >> num;
				s.push(num);
			}
			else if (arr[1] == 'o') {//pop
				if (s.empty() == 1) printf("-1\n");
				else {
					printf("%d\n", s.top());
					s.pop();
				}
			}
		}
		else if (arr[0] == 's') {//size
			printf("%d\n", s.size());
		}
		else if (arr[0] == 'e') {//empty
			if (s.empty() == 1) printf("1\n");
			else printf("0\n");
		}
		else if (arr[0] == 't') {//top
			if (s.empty() == 1) printf("-1\n");
			else printf("%d\n", s.top());
		}
	}
}