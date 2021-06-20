#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct student {
	string name;
	int kor, eng, math;
};
bool cmp(student a, student b) {
	if (a.kor == b.kor && a.eng == b.eng && a.math == b.math)
		return a.name < b.name;
	if (a.kor == b.kor && a.eng == b.eng)
		return a.math > b.math;
	if (a.kor == b.kor)
		return a.eng < b.eng;
	return a.kor > b.kor;

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<student>arr;
	for (int i = 0; i < n; i++) {
		string name; cin >> name;
		int a, b, c; cin >> a >> b >> c;
		arr.push_back({ name,a,b,c });
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << arr[i].name << "\n";
	}
	return 0;
}