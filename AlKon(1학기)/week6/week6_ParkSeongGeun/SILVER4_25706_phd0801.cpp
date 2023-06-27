#include <bits/stdc++.h>

using namespace std;

int N;
int road[200001];
int dp[200001];

//9
//0 1 0 2 1 0 0 3 0
int go(int k) {
	if (k == N) {
		return dp[k]=1;
	}
	if (road[k] + k > N) {
		return dp[k]=1;
	}
	if (road[k] != 0) {
		return dp[k] = dp[k + (road[k]+1)] + 1;
	}
	return dp[k] = dp[k + 1] + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> road[i];
	}
	for (int i = N; i >= 1; i--) {
		go(i);
	}
	for (int i = 1; i <= N; i++) {
		cout<<dp[i]<<" ";
	}
	return 0;
}