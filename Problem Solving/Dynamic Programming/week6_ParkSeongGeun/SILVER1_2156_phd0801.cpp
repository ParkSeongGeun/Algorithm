#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];
int dp[100001];

int go(int N) {
	for (int i = 3; i <= N; i++) {
		dp[i] = max({ dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i], dp[i - 1]});
	}
	return dp[N];	
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	cout << go(n) << "\n";
}