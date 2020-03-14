#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll arr[101];
bool visited[101];
vector<ll>res;
ll n;

bool game() {
	if (res.size() == n) {
		for (int i = 0; i < n; i++)
			cout << res[i] << ' ';
		return true;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == false && (res.back() * 2 == arr[i] || res.back() == arr[i] * 3)) {
			visited[i] = true;
			res.push_back(arr[i]);
			if (game())
				return true;
			visited[i] = false;
			res.pop_back();
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		res.push_back(arr[i]);
		visited[i] = true;
		if (game())
			return 0;
		res.clear();
		visited[i] = false;
	}
	return 0;
}