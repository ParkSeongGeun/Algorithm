#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < 2 * N - 1; i++) { // N�� �Է��ϸ� 2*N-1�ٱ��� �׾���
		if (i < N) { // N���� �ٱ���
			for (int j = N - i - 1; j > 0; j--) { // 
				cout << " "; // ������ ����ϰ� ( ������ ���� ���� ���� ) -> i ���� �� N-i-1 ����
			}
			for (int j = 0; j < 2 * i + 1; j++) {
				cout << "*"; // ���� ����� ( ���� ���� ���� ���� )
			}
			cout << "\n";
		}
		else { // N+1~2*N-1��° �ٱ���
			for (int j = 0; j < i - N + 1; j++) {
				cout << " "; // ������ ����ϰ� ( ������ ���� ���� ���� ) -> i ���� �� i-N+1 ����
			}
			for (int j = 2 * (2 * N - i) - 3; j > 0; j--) {
				cout << "*"; // ���� ����� ( ���� ���� ���� ���� )
			}
			cout << "\n";
		}
	}
}