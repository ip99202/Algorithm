#include <iostream>
using namespace std;
int gcd(int a, int b);
int main(void) {
    int roof;
    cin >> roof;
    for (int i = 0; i < roof; i++) {
        int num;
        cin >> num;
        int arr[101];
        for (int j = 0; j < num; j++) {
            cin >> arr[j];
        }
        long long sum_gcd = 0;
        for (int j = 0; j < num - 1; j++) {
            for (int k = j + 1; k < num; k++) {
                int a, b;
                if (arr[j] > arr[k]) {
                    a = arr[j];
                    b = arr[k];
                }
                else {
                    b = arr[j];
                    a = arr[k];
                }
                sum_gcd += gcd(a, b);
            }
        }
        printf("%lld\n", sum_gcd);
    }
}
int gcd(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}