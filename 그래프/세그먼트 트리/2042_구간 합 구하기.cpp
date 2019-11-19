#include<iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int arr[11][11];//최대 10*10 행렬이 올 수 있기 때문에 11*11로 설정했다.
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {//arr 배열에 입력받은 값들을 저장한다.
			for (int j = 1; j <= n; j++) {
				int x;
				scanf("%d", &x);
				arr[i][j] = x;
			}
		}
		for (int k = 1; k <= n; k++) {//k번(정점의 갯수)만큼 반복하며 값을 갱신한다.
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (arr[i][k] == 1 && arr[k][j] == 1)//ik를 지나고 kj를 지난다면 ij를 지난다.
						arr[i][j] = 1;//추이적 관계를 구하는 과정
				}
			}
		}//반복문이 끝나게되면 transitive closure을 구할 수 있게 된다.
		for (int i = 1; i <= n; i++) {//출력하는 과정
			for (int j = 1; j <= n; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}