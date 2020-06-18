#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char arr[501][501];
int dist[2][501][501];
bool visited[2][501][501];
struct play {
    int y, x, state, turn;
    bool operator<(const play& tmp) const {
        return turn > tmp.turn;
    }
};
priority_queue<play, vector<play>> pq;
int n, t, r, c;

int dijkstra() {
    pq.push({ 0, 0, 0, 0 });
    dist[0][0][0] = 0;
    while (!pq.empty()) {
        play now = pq.top();
        pq.pop();
        if (now.y == r && now.x == c)
            return now.turn;
        if (visited[now.state][now.y][now.x])
            continue;
        visited[now.state][now.y][now.x] = true;
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (visited[0][ny][nx])
                    continue;
                if (dist[0][ny][nx] >= now.turn + 1) {
                    dist[0][ny][nx] = now.turn + 1;
                    pq.push({ ny, nx, 0, dist[0][ny][nx] });
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = now.x;
            int ny = now.y;
            bool warp = false;
            while (!warp) {
                nx += dx[i];
                ny += dy[i];
                if (!(0 <= ny && ny < n && 0 <= nx && nx < n))
                    break;
                if (arr[ny][nx] == '#')
                    warp = true;
            }
            int flag;
            if (now.state) flag = 0;
            else flag = 1;
            int next = now.turn + 1 + flag * t;
            if (warp && dist[1][ny][nx] > next) {
                if (visited[1][nx][ny])
                    continue;
                dist[1][ny][nx] = next;
                pq.push({ ny, nx, 1, dist[1][ny][nx] });
            }
        }
    }
    return min(dist[0][r][c], dist[1][r][c]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> t >> r >> c;
    r -= 1, c -= 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    fill(dist[0][0], dist[1][500], 1e9);

    cout << dijkstra();
    return 0;
}
