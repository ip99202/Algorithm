#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
typedef pair<int, int>P;
stack<P>arr;
vector<int>res;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int now;
        cin >> now;
        if (i == 1) {
            arr.push(P(now, i));
            res.push_back(0);
            continue;
        }
        if (now > arr.top().first) {
            while (arr.size()) {
                if (arr.top().first >= now)
                    break;
                arr.pop();
            }
            if (arr.size() == 0)
                res.push_back(0);
            else
                res.push_back(arr.top().second);
        }
        else {
            res.push_back(arr.top().second);
        }
        arr.push(P(now, i));
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    return 0;
}