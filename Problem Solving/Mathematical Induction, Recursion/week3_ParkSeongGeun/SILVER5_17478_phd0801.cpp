#include <bits/stdc++.h>	

using namespace std;

int cnt;
int K;

void print_result(int N) {
	if (N == 0) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4 * (K - N); j++) {
				cout << "_";
			}
			if (i == 0) {
				cout << "\"����Լ��� ������?\"" << "\n";
			}
			else if (i == 1) {
				cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
			}
			else {
				cout << "��� �亯�Ͽ���." << "\n";
			}
		}
		for (int i = cnt; i > 0; i--) {
			for (int j = 0; j < (cnt-1) * 4; j++) {
				cout << "_";
			}
			cout << "��� �亯�Ͽ���."<<"\n";
			cnt--;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4*(K-N); j++) {
			cout << "_";
		}
		if (i == 0) {
			cout << "\"����Լ��� ������?\""<<"\n";
		}
		else if (i == 1) {
			cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���."<<"\n";
		}
		else if (i == 2) {
			cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
		}
		else {
			cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";
		}
	}
	print_result(N - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K;
	cnt = K;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	print_result(K);
}