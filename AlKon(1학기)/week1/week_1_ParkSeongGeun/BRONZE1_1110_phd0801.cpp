#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int M = N; // �ʱ� �Է��� N�� ���� �����ϴ� M ����
	int count = 0; // ��� Ƚ�� count ����
	while (1) {
		if (M == N && count != 0) { // �ʱ� �Է��� N�� ��� ���� N�� ��������, �� �� �ݺ�Ƚ���� 0�� �ƴϸ� �ݺ��� ����
			cout << count << "\n";
			break;
		}
		if (N < 10) { // N�� 10���� ���� �� ����
			N = N + (N * 10);
		}
		else { // N�� 10 �̻��� �� ����
			N = N % 10 * 10 + (((N / 10) + (N % 10)) % 10);
		} // ���ǹ� ������ count++;
		count++;
	}
	return 0;
}