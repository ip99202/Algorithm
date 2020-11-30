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
        cnt[now] += cnt[next]; // �ڽĳ���� ����Ʈ���� �θ���� �����ذ�
    }

    iter = apt.find(now);
    if (iter != apt.end()) { // �ڱ��ڽ��� ����Ʈ�� ������ �ִٸ� �н�
        cnt[now]++; // ����Ʈ�� ���� �����س��� �迭
        return;
    }
    if (cnt[now] == 0 || chk) // �ڽĳ�尡 ����Ʈ�� �ϳ��� ���°�� 
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