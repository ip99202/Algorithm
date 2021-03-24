#include<iostream>
#include<algorithm>
using namespace std;
int index, num[6], oper[4];
int n, sum, Max = -1000000000, Min = 1000000000;

void go(int index, int plus, int sub, int multi, int div, int sum) {
	if (index == n) {
		Max = max(Max, sum);
		Min = min(Min, sum);
		return;
	}
	if (plus > 0)
		go(index + 1, plus - 1, sub, multi, div, sum + num[index]);
	if (sub > 0)
		go(index + 1, plus, sub - 1, multi, div, sum - num[index]);
	if (multi > 0)
		go(index + 1, plus, sub, multi - 1, div, sum * num[index]);
	if (div > 0)
		go(index + 1, plus, sub, multi, div - 1, sum / num[index]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	go(1, oper[0], oper[1], oper[2], oper[3], num[0]);
	cout << Max << endl << Min;
}