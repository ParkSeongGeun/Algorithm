#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int wine[10001];
int dp[10001][3];

int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> wine[i];
    }

    dp[0][0] = 0; // 1번째 선택x
    dp[0][1] = wine[0]; // 1번째 선택o
    dp[0][2] = 0;

    dp[1][0] = max(dp[0][0], dp[0][1]);  // 1번째까지의 최댓값
    dp[1][1] = dp[0][0] + wine[1];       // 1번째 선택X + 2번째 선택
    dp[1][2] = dp[0][1] + wine[1];       // 1번째 선택 + 2번째 선택 (연속2개)

    for(int i=2;i<n;i++) {
        dp[i][0] = max(
            dp[i-1][0], 
            max(dp[i-1][1], dp[i-1][2])
        );

        dp[i][1] = dp[i-1][0] + wine[i];

        dp[i][2] = dp[i-1][1] + wine[i];
    }

    int res = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));

    cout << res << "\n";
    return 0;
}