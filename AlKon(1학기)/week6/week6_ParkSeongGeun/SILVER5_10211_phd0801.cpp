#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int arr[1001];
int dp[1001];

int go() { // bottom-up
	int max_val = -987654321;
	for (int i = 1; i <= N; i++) {
		if (dp[i - 1] >= 0) {
			dp[i] = dp[i - 1] + arr[i];
		}
		else {  // dp[i - 1] < 0
			dp[i] = max(dp[i - 1] + arr[i], arr[i]);  // arr[i]도 음수일 때 고려 
		}
		max_val = max(max_val, dp[i]);
	}
	return max_val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		cout << go() << "\n";
	}
	return 0;
}
