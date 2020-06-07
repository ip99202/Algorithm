#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int>P;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<P>arr(n);
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr[i].first = a * 100 + b;
		arr[i].second = c * 100 + d;
	}
	sort(arr.begin(), arr.end());

    int res = 0, date = 301, flag = 0, i = -1, now = 0;
    while (date <= 1130 && i < n) {
        flag = 0;
        i++;
        for (int j = i; j < n; ++j) {
            if (arr[j].first > date)
                break;
            if (now < arr[j].second) {
                now = arr[j].second;
                flag = 1;
                i = j;
            }
        }

        if (flag) {
            date = now;
            res++;
        }
        else {
            cout << 0;
            return 0;
        }
    }
	cout << res;
	return 0;
}