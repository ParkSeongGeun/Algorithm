#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
int dp[1001];

int main() {
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    // 초기화
    dp[1] = arr[1];

    if (n==1) {
        cout << dp[1] << "\n";
        return 0;
    }

    dp[2] = max(arr[2], dp[1] + dp[1]);

    for(int i=3;i<=n;i++){
        for(int j=i-1;j>=1;j--) {
            dp[i] = max(dp[i], dp[i-j] + dp[j]);
        }
        dp[i] = max(dp[i], arr[i]);
    }

    cout << dp[n] << "\n";
    return 0;
}