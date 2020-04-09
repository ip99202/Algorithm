#include<iostream>
using namespace std;

int main() {
	int n, num, temp, res, flag = 0;
	int arr[3];
	scanf("%d", &num);

	if (num < 100) res = num;
	else if (num == 1000) res = 144;
	else {
		res = 99;
		for (int i = 100; i <= num; i++) {
			n = i;
			for (int k = 1; k < sizeof(n); k++) {
				arr[k - 1] = n % 10;
				n = n / 10;
			}
			temp = arr[0];
			arr[0] = arr[2];
			arr[2] = temp;
			for (int j = -4; j <= 4; j++) {
				if (arr[0] + j == arr[1] && arr[1] + j == arr[2])
					flag = 1;
			}
			if (flag == 1)
				res++;
			flag = 0;
		}
	}
	printf("%d", res);
}