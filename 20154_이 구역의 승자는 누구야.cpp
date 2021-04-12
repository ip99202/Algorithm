#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<limits.h>
#include<queue>
using namespace std;
typedef pair<int, int>P;
typedef long long ll;
int arr[] = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string x; cin >> x;
	int len = x.length();
	bool flag = false;
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[x[i] - 'A'];
		sum %= 10;
	}
	if (sum % 2)
		cout << "I'm a winner!";
	else
		cout << "You're the winner?";
	return 0;
}