#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll dp[20][20];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k; cin >> n >> m >> k;

    dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    if (k == 0)
        cout << dp[n][m];
    else {
        int x, y, tx, ty;
        x = k / m + (k % m > 0 ? 1 : 0);
        y = k - (x - 1) * m;
        tx = n - x + 1;
        ty = m - y + 1;
        cout << dp[x][y] * dp[tx][ty];
    }
    return 0;
}