#include <bits/stdc++.h>	

using namespace std;

int N;
// { 0 , 1 }
pair<long long, long long> dp[91];

pair<long long, long long> go(int N) {
	dp[0] = make_pair(0, 1);
	dp[1] = make_pair(1, 0);
	for (int i =2 ; i < N; i++) {
		dp[i].first = dp[i - 1].first+ dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}
	return dp[N - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	if (N == 1 || N == 2) {
		cout << 1 << "\n";
		return 0;
	}
	long long ans = go(N).first + go(N).second;
	cout << ans<<"\n";
	return 0;
}