#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

double attack(vector<double>& h, vector<double>& w) {
	return (h[0] + w[0]) * (1 + (h[1] + w[1]) / 100) * ((1 - min((h[2] + w[2]) / 100, 1.0)) + min((h[2] + w[2]) / 100, 1.0) * ((h[3] + w[3])) / 100) * (1 + (h[4] + w[4]) / 100);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<double>h1, h2, w1, w2;
	for (int i = 0; i < 5; i++) { double a; cin >> a; h1.push_back(a); }
	for (int i = 0; i < 5; i++) { double a; cin >> a; h2.push_back(a); }
	for (int i = 0; i < 5; i++) { double a; cin >> a; w1.push_back(a); }
	for (int i = 0; i < 5; i++) { double a; cin >> a; w2.push_back(a); }
	for (int i = 0; i < 5; i++) { double a; h1[i] -= w1[i]; }
	for (int i = 0; i < 5; i++) { double a; h2[i] -= w2[i]; }

	double cree_pabu = attack(h1, w2) - attack(h1, w1);
	double pabu_cree = attack(h2, w1) - attack(h2, w2);

	if (cree_pabu > 0) cout << "+";
	else if (cree_pabu < 0) cout << "-";
	else cout << "0";
	cout << "\n";
	if (pabu_cree > 0) cout << "+";
	else if (pabu_cree < 0) cout << "-";
	else cout << "0";
	return 0;
}