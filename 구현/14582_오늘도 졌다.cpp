#include<iostream>
#include<vector>
using namespace std;
vector<int>v1, v2;

int main() {
	int x, sc1 = 0, sc2 = 0;
	bool v_flag = false;
	v1.reserve(9);
	v2.reserve(9);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &x);
		v1.push_back(x);
	}
	for (int i = 0; i < 9; i++) {
		scanf("%d", &x);
		v2.push_back(x);
	}
	for (int i = 0; i < 9; i++) {
		sc1 += v1[i];
		if (sc1 > sc2)
			v_flag = true;
		sc2 += v2[i];
	}
	if (v_flag == true)
		printf("Yes");
	else
		printf("No");
}