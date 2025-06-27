#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1000000]={0,1};

int go(int N) {
	if (N == 1) {
		return 1;
	}
	if (N == 2) {
		return 2;
	}
	if (dp[N] > 0) {
		return dp[N];
	}
	return dp[N] = (go(N - 1) + go(N-2))%10007;
}

int main() {
	cin >> N;
	cout << go(N) << "\n";
	return 0;
}