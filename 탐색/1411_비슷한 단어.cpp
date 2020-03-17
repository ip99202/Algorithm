#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<string>arr;
int cnt;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int chk1[27] = { 0 };
            int chk2[27] = { 0 };
            bool flag = true;
            for (int k = 0; k < arr[i].size(); k++) {
                int x = arr[i][k] - 'a' + 1;
                int y = arr[j][k] - 'a' + 1;
                if (chk1[x] == 0 && chk2[y] == 0) {
                    chk1[x] = y;
                    chk2[y] = x;
                }
                else if (chk1[x] != y)
                    flag = false;
            }
            if (flag)
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}