#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
typedef pair<int, char>P;
struct Apple {
	int x, y, flag;
};
struct Snake {
	int x, y, dir;
	// 1:µ¿ 2:³² 3:¼­ 4:ºÏ
};
deque<Snake>snake;
deque<Apple>apple;
deque<P>dir;
int stime, n, k;

bool add_snake(int x, int y, int dir) {
	for (int i = 0; i < snake.size(); i++) {
		if ((snake[i].x == x && snake[i].y == y) ||
			(x<1 || y<1 || x>n || y>n)) {
			cout << stime + 1;
			return false;
		}
	}
	snake.push_front({ x,y,dir });
	bool tmp = false;
	if (!apple.empty()) {
		for (int i = 0; i < apple.size(); i++) {
			if (apple[i].x == x && apple[i].y == y && apple[i].flag) {
				apple[i].flag = false;
				tmp = true;
			}
		}
	}
	if (!tmp || apple.empty())
		snake.pop_back();
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y; cin >> y >> x;
		apple.push_back({ x,y,true });
	}
	int l; cin >> l;
	dir.resize(l);
	for (int i = 0; i < l; i++)
		cin >> dir[i].first >> dir[i].second;

	snake.push_back({ 1,1,1 });
	for (stime = 0;; stime++) {
		int d = snake.front().dir;
		int x = snake.front().x;
		int y = snake.front().y;
		if (!dir.empty()) {
			if (stime == dir.front().first) {
				if (dir.front().second == 'D') {
					if (d == 4) d = 1;
					else d++;
				}
				else {
					if (d == 1) d = 4;
					else d--;
				}
				if (!dir.empty())
					dir.pop_front();
			}
		}
		if (d == 1) {
			if (!add_snake(x + 1, y, 1))
				return 0;
		}
		else if (d == 2) {
			if (!add_snake(x, y + 1, 2))
				return 0;
		}
		else if (d == 3) {
			if (!add_snake(x - 1, y, 3))
				return 0;
		}
		else if (d == 4) {
			if (!add_snake(x, y - 1, 4))
				return 0;
		}
	}
	return 0;
}