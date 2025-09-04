#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int n;
int arr[301];
int dp[301][2];

int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    // 초기 세팅
    dp[0][0] = arr[0];
    dp[0][1] = 0;

    dp[1][0] = dp[0][0] + arr[1];
    dp[1][1] = arr[1];

    for(int i=2;i<n-1;i++) {
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + arr[i];

        dp[i][1] = dp[i-1][0] + arr[i];
    }

    // 마지막 계단 점수를 더한다.
    dp[n-1][0] = max(dp[n-3][0], dp[n-3][1]) + arr[n-1];
    dp[n-1][1] = max(dp[n-3][1], dp[n-2][0]) + arr[n-1];

    cout << max(dp[n-1][0], dp[n-1][1]) << "\n";
    return 0;
}