#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef pair<int, int>P;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<string>name;
    vector<P>arr;
    string a;
    getline(cin, a);
    for (int i = 0; i < n; i++) {
        string x;
        getline(cin, x);
        name.push_back(x);
        arr.push_back({ 0,i });
    }
    int cnt = 0;
    vector<queue<int>>score(1001);

    int x;
    while (cin >> x) {
        x--;
        score[cnt].push(x);
        for (int i = 1; i < n; i++) {
            int x; cin >> x; x--;
            score[cnt].push(x);
        }
        cnt++;
    }

    while (true) {
        for (int i = 0; i < cnt; i++) {
            while (arr[score[i].front()].first == -1) {
                score[i].pop();
            }
            arr[score[i].front()].first++;
        }

        int maxx = 0;
        int minn = 999999999;
        for (int i = 0; i < n; i++) {
            if (maxx < arr[i].first)
                maxx = arr[i].first;
            if (minn > arr[i].first && arr[i].first != -1)
                minn = arr[i].first;
        }

        if (maxx * 2 > cnt || maxx == minn) {
            for (int i = 0; i < n; i++) {
                if (arr[i].first == maxx)
                    cout << name[arr[i].second] << "\n";
            }
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (arr[i].first == minn) {
                arr[i].first = -1;
            }
            if (arr[i].first == -1) continue;
            arr[i].first = 0;
        }
    }
    return 0;
}