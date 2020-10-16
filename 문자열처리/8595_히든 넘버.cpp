#include<iostream>
#include<vector>
#include<string>
using namespace std;
char arr[5000001];

int main() {
	int n;
	long long sum = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
		scanf("%c", &arr[i]);

	for (int i = 0; i < n; i++) {
		int j = 0;
		bool flag = false;
		string temp = "";
		if (arr[i] >= '0' && arr[i] <= '9') {
			while (true) {
				if (arr[i + j] >= '0' && arr[i + j] <= '9') {
					temp += arr[i + j];
					j++;
					flag = true;
				}
				else
					break;
			}
		}
		if (flag == true) {
			i += (j - 1);
			int v = atoi(temp.c_str());
			sum += v;
		}
	}
	printf("%lld", sum);
}