#include<iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int arr[11][11];//�ִ� 10*10 ����� �� �� �ֱ� ������ 11*11�� �����ߴ�.
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {//arr �迭�� �Է¹��� ������ �����Ѵ�.
			for (int j = 1; j <= n; j++) {
				int x;
				scanf("%d", &x);
				arr[i][j] = x;
			}
		}
		for (int k = 1; k <= n; k++) {//k��(������ ����)��ŭ �ݺ��ϸ� ���� �����Ѵ�.
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (arr[i][k] == 1 && arr[k][j] == 1)//ik�� ������ kj�� �����ٸ� ij�� ������.
						arr[i][j] = 1;//������ ���踦 ���ϴ� ����
				}
			}
		}//�ݺ����� �����ԵǸ� transitive closure�� ���� �� �ְ� �ȴ�.
		for (int i = 1; i <= n; i++) {//����ϴ� ����
			for (int j = 1; j <= n; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}