#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef pair<int, int>P;
vector<vector<P>>arr;
int cnt[100001], visited[100001], res, n, k;
set<int>apt;
set<int>::iterator iter;

void dfs(int now) {
    visited[now] = true;
    int len = arr[now].size();
    bool chk = false;
    for (int i = 0; i < len; i++) {
        int next = arr[now][i].first;
        if (visited[next]) continue;
        dfs(next);
        if (cnt[next] == k) chk = true;
        cnt[now] += cnt[next]; // 자식노드의 아파트개수 부모노드로 더해준것
    }

    iter = apt.find(now);
    if (iter != apt.end()) { // 자기자신이 아파트를 가지고 있다면 패스
        cnt[now]++; // 아파트의 개수 저장해놓은 배열
        return;
    }
    if (cnt[now] == 0 || chk) // 자식노드가 아파트가 하나도 없는경우 
        res++;
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    arr.resize(n + 1);
    for (int k = 1; k < n; k++) {
        int i, j, w; cin >> i >> j >> w;
        arr[i].push_back({ j,w });
        arr[j].push_back({ i,w });
    }

    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        apt.insert(x);
    }
    dfs(1);
    cout << n - res;
    return 0;
}