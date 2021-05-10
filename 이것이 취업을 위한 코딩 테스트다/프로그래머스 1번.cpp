#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
typedef pair<int, int>P;
typedef pair<P, int>PP;

vector<string> split(string str) {
	istringstream ss(str);
	string stringBuffer;
	vector<string> x;
	x.clear();
	while (getline(ss, stringBuffer, ' '))
		x.push_back(stringBuffer);
	return x;
}
string split2(string str) {
	istringstream ss(str);
	string stringBuffer;
	vector<string> x;
	x.clear();
	while (getline(ss, stringBuffer, '='))
		x.push_back(stringBuffer);
	return x[1];
}

vector<int> solution(string code, string day, vector<string> data) {
	vector<int> answer;
	vector<P>arr;
	for (int i = 0; i < data.size(); i++) {
		vector<string>tmp = split(data[i]);
		int price = stoi(split2(tmp[0]));
		string now_code = split2(tmp[1]);
		string time = split2(tmp[2]);

		string tttt = "";
		for (int i = 0; i < 8; i++) {
			tttt += time[i];
		}

		if (now_code == code && day == tttt) {
			arr.push_back({ stoi(time), price });
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		answer.push_back(arr[i].second);
	}
	return answer;
}