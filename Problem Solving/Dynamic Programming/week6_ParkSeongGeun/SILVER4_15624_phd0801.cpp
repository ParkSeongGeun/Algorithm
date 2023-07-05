#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1000001]={0,1};

int fibo(int N) {
	if (N <= 1) {
		return dp[N];
	}
	if (dp[N] > 0) {
		return dp[N];
	}
	return dp[N] = (fibo(N - 1) + fibo(N - 2))% 1000000007;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int k = fibo(N);
	cout << k << "\n";
	return 0;
}