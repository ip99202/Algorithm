#include<iostream>
using namespace std;
char arr[9][9];
int flag[8][8];

int main() {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j += 2) {
				flag[i][j] = 1;
			}
		}
		else if (i % 2 == 1) {
			for (int j = 1; j < 8; j += 2) {
				flag[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] == 'F' && flag[i][j] == 1)
				cnt++;
		}
	}
	printf("%d", cnt);
}