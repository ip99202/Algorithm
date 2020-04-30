#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
stack<int>res;

struct Point {
	int x, y;
	int p, q;
	Point() :Point(0, 0, 1, 0) {}
	Point(int x1, int y1) :Point(x1, y1, 1, 0) {}
	Point(int x1, int y1, int p1, int q1) : x(x1), y(y1), p(p1), q(q1) {}
};
Point p[100000];

bool comp(Point& A, Point& B) {
	if (1LL * A.q * B.p != 1LL * A.p * B.q)
		return 1LL * A.q * B.p < 1LL * A.p * B.q;
	if (A.y != B.y)
		return A.y < B.y;
	return A.x < B.x;
}

ll ccw(Point& A, Point& B, Point& C) {
	return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		p[i] = Point(x, y);
	}
	sort(p, p + n, comp);
	for (int i = 1; i < n; i++) {
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p + 1, p + n, comp);
	res.push(0);
	res.push(1);
	int next = 2;
	while (next < n) {
		while (res.size() >= 2) {
			int first = res.top();
			res.pop();
			int second = res.top();
			if (ccw(p[second], p[first], p[next]) > 0) {
				res.push(first);
				break;
			}
		}
		res.push(next++);
	}
	cout << res.size();
	return 0;
}