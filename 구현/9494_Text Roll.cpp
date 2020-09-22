#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int res, n;
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		getchar();
		for (int i = 0; i < n; i++) {
			int temp = 0;
			char arr[105];
			cin.getline(arr, 105);
			for (int j = 0; j <= strlen(arr); j++) {
				if (i == 0) {
					if (arr[j] == ' ') {
						res = j + 1;
						break;
					}
					if (j == strlen(arr)) {
						res = strlen(arr) + 1;
						break;
					}
				}
				else {
					if (arr[j] == ' ') {
						if (res - 1 <= j) {
							temp = j + 1;
							if (temp > res)
								res = temp;
							break;
						}
					}
					if (j == strlen(arr)) {
						temp = strlen(arr) + 1;
						if (temp > res)
							res = temp;
						break;
					}
				}
			}
		}
		cout << res << endl;
	}
}