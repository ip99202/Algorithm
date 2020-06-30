#include<iostream>

using namespace std;

int main() {
	int i, n, k, now = 0, record[103] = { 0 }, cnt = 1;
	char str[6];
	scanf("%d %d", &n, &k);
	for (i = 0; i < k; i++) {
		int num;
		scanf("%s", str);
		if (str[0] != 'u') {
			num = atoi(str);
			now += num;
			if (now < 0) { now = (n - (now * -1) % n) % n; }
			else { now %= n; }
			record[cnt++] = now;
		}
		else {
			scanf("%d", &num);
			cnt = cnt - num;
			now = record[cnt - 1];
		}
	}
	printf("%d", now);

	return 0;
}