#include <bits/stdc++.h>
#define MAX 1001000

using namespace std;

int A, K;
int dp[MAX];	
int go(int start_node) {
	for (int i = A + 1; i <= K; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0 && i / 2 >= A) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}
	return dp[K];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> K;
	cout<< go(K);
	return 0;
}