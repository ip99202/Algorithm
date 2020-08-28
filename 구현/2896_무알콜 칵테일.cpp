#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
typedef pair<double, double>P;

int main() {
	double a, b, c, i, j, k;
	P arr[3];
	scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &i, &j, &k);
	arr[0].first = a; arr[0].second = i;
	arr[1].first = b; arr[1].second = j;
	arr[2].first = c; arr[2].second = k;
	int flag = 0;
	double temp = a / i;
	for (int i = 0; i < 3; i++) {
		if (temp > arr[i].first / arr[i].second) {
			temp = arr[i].first / arr[i].second;
			flag = i;
		}
	}
	printf("%f %f %f", a - (i * temp), b - (j * temp), c - (k * temp));
}