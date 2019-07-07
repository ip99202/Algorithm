#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main() {
	while (true) {
		int h, m;
		cin >> h;
		getchar();
		cin >> m;
		int dh, dm;
		cin >> dh;
		getchar();
		cin >> dm;
		if (h == 0 && m == 0 && dh == 0 && dm == 0)
			break;
		int rh = 0, rm = 0, n = 0;
		rm = m + dm;
		if (rm > 59) {
			rm = rm - 60;
			rh++;
		}
		rh += (h + dh);
		while (rh >= 24) {
			rh = rh - 24;
			n++;
		}
		string zh;
		if (rh == 0)
			zh = "00";
		else {
			zh += (rh / 10) + '0';
			zh += (rh % 10) + '0';
		}
		string zm;
		if (rm == 0)
			zm = "00";
		else {
			zm += (rm / 10) + '0';
			zm += (rm % 10) + '0';
		}
		if (n != 0)
			cout << zh << ':' << zm << " +" << n << "\n";
		else
			cout << zh << ':' << zm << "\n";
	}
}