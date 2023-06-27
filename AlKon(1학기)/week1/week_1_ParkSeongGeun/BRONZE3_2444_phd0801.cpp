#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < 2 * N - 1; i++) { // N을 입력하면 2*N-1줄까지 그어짐
		if (i < N) { // N번재 줄까지
			for (int j = N - i - 1; j > 0; j--) { // 
				cout << " "; // 공백을 출력하고 ( 공백의 수가 점점 감소 ) -> i 증가 시 N-i-1 감소
			}
			for (int j = 0; j < 2 * i + 1; j++) {
				cout << "*"; // 별을 출력함 ( 별의 수가 점점 증가 )
			}
			cout << "\n";
		}
		else { // N+1~2*N-1번째 줄까지
			for (int j = 0; j < i - N + 1; j++) {
				cout << " "; // 공백을 출력하고 ( 공백의 수가 점점 증가 ) -> i 증가 시 i-N+1 증가
			}
			for (int j = 2 * (2 * N - i) - 3; j > 0; j--) {
				cout << "*"; // 별을 출력함 ( 별의 수가 점점 감소 )
			}
			cout << "\n";
		}
	}
}