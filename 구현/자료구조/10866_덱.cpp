#include <iostream>
#include <deque>
#include <string.h>
using namespace std;

int main() {
	deque<int>d;
	int n, num;
	char arr[20];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr;
		if (arr[0] == 'p') {
			if (arr[5] == 'f') {//push_fornt
				cin >> num;
				d.push_front(num);
			}
			else if (arr[5] == 'b') {//push_back
				cin >> num;
				d.push_back(num);
			}
			else if (arr[4] == 'f') {//pop_fornt
				if (d.empty() == 1) printf("-1\n");
				else {
					printf("%d\n", d.front());
					d.pop_front();
				}
			}
			else if (arr[4] == 'b') {//pop_back
				if (d.empty() == 1) printf("-1\n");
				else {
					printf("%d\n", d.back());
					d.pop_back();
				}
			}
		}
		else if (arr[0] == 's') {//size
			printf("%d\n", d.size());
		}
		else if (arr[0] == 'e') {//empty
			if (d.empty() == 1) printf("1\n");
			else printf("0\n");
		}
		else if (arr[0] == 'f') {//fornt
			if (d.empty() == 1) printf("-1\n");
			else printf("%d\n", d.front());
		}
		else if (arr[0] == 'b') {//back
			if (d.empty() == 1) printf("-1\n");
			else printf("%d\n", d.back());
		}
	}
}