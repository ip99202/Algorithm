#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int Garmy[6] = { 1,2,3,3,4,10 };
	int Sarmy[7] = { 1,2,2,2,3,5,10 };
	int n, Gscore = 0, Sscore = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 6; j++) {
			int x;
			cin >> x;
			Gscore += Garmy[j] * x;
		}
		for (int k = 0; k < 7; k++) {
			int x;
			cin >> x;
			Sscore += Sarmy[k] * x;
		}
		cout << "Battle " << i << ": ";
		if (Gscore > Sscore)
			cout << "Good triumphs over Evil";
		else if (Gscore < Sscore)
			cout << "Evil eradicates all trace of Good";
		else
			cout << "No victor on this battle field";
		cout << '\n';
		Gscore = 0;
		Sscore = 0;
	}
	return 0;
}