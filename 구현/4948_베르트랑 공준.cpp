#include<iostream>
#include<math.h>
using namespace std;

int main() {
	while (true) {
		int x, cnt = 0;
		cin >> x;
		if (x == 0)
			break;
		for (int i = x + 1; i < 2 * x + 1; i++) {
			bool flag = true;
			for (int j = 2; j <= sqrt(i); j++) {
				if (i % j == 0) {
					flag = false;
					break;
				}
			}
			if (flag == true)
				cnt++;
		}
		cout << cnt << '\n';
	}
}