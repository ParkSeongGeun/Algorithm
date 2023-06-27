#include <bits/stdc++.h>

using namespace std;

int N;
int arr[2000];
int dp[2000] = { 0,1 };
int go(int N) {
	for (int i = 1; i <= N; i++) {
		if (dp[i] == 0) {
			break;
		}
		for (int j = 1; j <= arr[i]; j++) {
			if (i + j > 1000) {
				break;
			}
			if (dp[i + j] > dp[i] + 1 || dp[i + j] == 0) {
				dp[i + j] = dp[i] + 1;
			}
		}
	}
	return dp[N];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	if(go(N)==0){
		cout << -1 << "\n";
		return 0;
	}
	else {
		cout << go(N) - 1 << "\n";
		return 0;
	}
}