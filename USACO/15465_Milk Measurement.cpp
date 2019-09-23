#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef pair<char, int>P;
typedef pair<int, P>PP;
vector<P>cow = { P('B',7) ,P('E',7),P('M',7) };
vector<PP>arr;
int val[27];

int main() {
	int n, res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int day, num;
		char name[10];
		char op;
		scanf("%d %s %c %d", &day, &name, &op, &num);
		int sum;
		if (op == '+')
			sum = num;
		else
			sum = -num;
		arr.push_back({ day,{name[0],sum} });
	}
	sort(arr.begin(), arr.end());
	int stan = 111;
	val['B' - 65] = val['E' - 65] = val['M' - 65] = 7;
	for (int i = 0; i < n; i++) {
		val[arr[i].second.first - 65] += arr[i].second.second;
		int milk = max(val['B' - 65], max(val['E' - 65], val['M' - 65]));
		int temp = 0;
		if (val['B' - 65] == milk)
			temp += 100;
		if (val['E' - 65] == milk)
			temp += 10;
		if (val['M' - 65] == milk)
			temp += 1;
		if (stan != temp) {
			stan = temp;
			res++;
		}
	}
	printf("%d", res);
}