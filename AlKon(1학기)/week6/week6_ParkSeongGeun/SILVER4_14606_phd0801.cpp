#include <bits/stdc++.h>

using namespace std;

int N;
int dp[11]={0,1};

int go(int N) {
	if (N == 1) {
		return 0;
	}
	if (dp[N] > 0) {
		return dp[N];
	}
	if (N % 2 == 0) {
		dp[N] = (N / 2) * (N / 2) + go(N / 2) + go(N / 2);
	}
	else {
		dp[N] = (N / 2) * (N / 2 + 1) + go(N / 2) + go(N / 2 + 1);
	}
	return dp[N];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	if (N == 1) {
		cout << 0 << "\n";
		return 0;
	}
	cout<< go(N) <<"\n";
}