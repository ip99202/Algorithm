#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Strahler {
    int max, order_cnt[1001], order;
};

int in[1001];
int k, kk, m, p, a, b;

int main() {
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d %d", &kk, &m, &p);
        for (int i = 1; i <= m; ++i)
            in[i] = 0;

        vector<vector<int>> vec(m + 1);
        for (int i = 0; i < p; ++i) {
            scanf("%d %d", &a, &b);
            vec[a].push_back(b);
            in[b]++;
        }

        vector<Strahler> st(m + 1);
        queue<int> q;
        for (int i = 1; i <= m; ++i) {
            if (!in[i]) {
                q.push(i);
                st[i].order = 1;
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto next : vec[cur]) {
                if (st[next].max < st[cur].order)
                    st[next].max = st[cur].order;

                st[next].order_cnt[st[cur].order]++;

                in[next]--;
                if (!in[next]) {
                    if (st[next].order_cnt[st[next].max] == 1)
                        st[next].order = st[next].max;
                    else if (st[next].order_cnt[st[next].max] > 1)
                        st[next].order = st[next].max + 1;
                    q.push(next);
                }
            }
        }
        printf("%d %d\n", kk, st[m].order);
    }
    return 0;
}
