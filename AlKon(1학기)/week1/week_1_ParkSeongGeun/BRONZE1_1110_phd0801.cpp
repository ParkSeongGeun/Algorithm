#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int M = N; // 초기 입력한 N의 값을 복사하는 M 생성
	int count = 0; // 계산 횟수 count 변수
	while (1) {
		if (M == N && count != 0) { // 초기 입력한 N과 계산 이후 N이 같아지고, 그 때 반복횟수가 0이 아니면 반복문 종료
			cout << count << "\n";
			break;
		}
		if (N < 10) { // N이 10보다 작을 때 계산법
			N = N + (N * 10);
		}
		else { // N이 10 이상일 때 계산법
			N = N % 10 * 10 + (((N / 10) + (N % 10)) % 10);
		} // 조건문 지나면 count++;
		count++;
	}
	return 0;
}