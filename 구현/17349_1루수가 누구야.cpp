#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>P;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<P>tmp(1);
    for (int i = 0; i < 9; i++) {
        int a, b; cin >> a >> b;
        tmp.push_back({ a,b });
    }
    vector<int>res;
    for (int k = 1; k <= 9; k++) {
        vector<int>lie(10, -1);
        for (int i = 1; i <= 9; i++) {
            if (k == i) {
                if (tmp[i].first == 1) {
                    if (lie[tmp[i].second] == -1)
                        lie[tmp[i].second] = 0;
                    else {
                        if (lie[tmp[i].second] != 0)
                            lie[tmp[i].second] = 2;
                    }
                }
                else {
                    if (lie[tmp[i].second] == -1)
                        lie[tmp[i].second] = 1;
                    else {
                        if (lie[tmp[i].second] != 1)
                            lie[tmp[i].second] = 2;
                    }
                }
            }
            else {
                if (lie[tmp[i].second] == -1)
                    lie[tmp[i].second] = tmp[i].first;
                else {
                    if (lie[tmp[i].second] != tmp[i].first)
                        lie[tmp[i].second] = 2;
                }
            }
        }

        vector<int>temp(10, 1);
        bool tmp = true;
        for (int i = 1; i <= 9; i++) {
            if (lie[i] == -1) continue;
            if (lie[i] == 1 || lie[i] == 2) {
                tmp = false;
                break;
            }
            temp[i] = 0;

        }

        if (tmp) {
            for (int i = 1; i <= 9; i++) {
                if (temp[i] == 1) {
                    res.push_back(i);
                }
            }
        }
        int cnt = 0, who;
        bool flag = true;
        for (int i = 1; i <= 9; i++) {
            if (lie[i] == 2) {
                flag = false;
                break;
            }
            if (lie[i] == 1) {
                cnt++;
                who = i;
            }
        }
        if (flag && cnt == 1)
            res.push_back(who);
    }
    if (res.size() == 0 || res.size() > 1)
        cout << -1;
    else
        cout << res.front();
    return 0;
}