#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1000001];

int go(int N) {
	if (N == 1) {
		return 0;
	}
	if (dp[N] > 0) {
		return dp[N];
	}
	dp[N] = go(N - 1) + 1;
	if (N % 3 == 0) {
		dp[N] = min(go(N / 3) + 1, dp[N]);
	}
	if (N % 2 == 0) {
		dp[N] = min(go(N / 2) + 1, dp[N]);
	}
	return dp[N];
}

int main() {
	cin >> N;
	cout << go(N) <<"\n";
	return 0;
}