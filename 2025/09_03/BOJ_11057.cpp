#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
ll sum, ans;
ll dp[1001][10];

void go(int num) {
    // Base Condition
    for(int i=0;i<=9;i++){
        dp[1][i] = 1;
        sum += dp[1][i];
    }

    ll cnt = 0;

    for(int i=0;i<=9;i++){
        dp[2][i] = sum;
        cnt += dp[2][i];
        sum -= dp[1][i];
    }

    // dp
    for(int i=3;i<=num;i++){
        ll af = 0;
        for(int j=0;j<=9;j++){
            dp[i][j] = cnt % 10007;
            cnt = ((cnt - dp[i-1][j]) % 10007 + 10007) % 10007;
            af += dp[i][j];
        }
        cnt = af % 10007;
    }

    // Debug
    // for(int i=num;i<=num;i++){
    //     for(int j=0;j<=9;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i=0;i<=9;i++){
        ans = (ans + dp[num][i]) % 10007;
    }

    cout << ans % 10007 << "\n";
    return;
}

int main() {
    cin >> N;
    go(N);
    return 0;
}