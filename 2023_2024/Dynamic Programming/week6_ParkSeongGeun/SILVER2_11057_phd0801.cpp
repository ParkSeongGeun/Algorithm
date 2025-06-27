#include <bits/stdc++.h>

using namespace std;

int N;
unsigned long long dp[1010][10]; // 0~9���� ���� � �ִ� ��, dp[0~N-1] �ٱ��� ������ ��� DP���̺�

long long go(int N) {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < 10; j++) { // dp[i][j]�� �ش� ���̺��� ����, ������ ���� ��Ģ���� ����
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= 10007;
		}
	}
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[N-1][i];
	}
	return sum%10007;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		dp[i][0] = 1;
	}
	for (int i = 0; i < 1010; i++) {
		dp[0][i] = 1;
	}
	cout<< go(N) <<"\n";
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			cout << dp[i][j]<<"  ";
		}
		cout << "\n";
	}*/ 
	return 0;
}