#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a;
long long dp[101][10];
int MOD = 1000000000;

void go() {
    // dp 초기화
    for(int i=1;i<=9;i++){
        dp[1][i] = 1;
    }

    for(int j=2;j<=a;j++) {
        for(int i=0;i<=9;i++){
            if (i==0) {
                dp[j][i] = dp[j-1][i+1] % MOD;
            } else if (i==9) {
                dp[j][i] = dp[j-1][i-1] % MOD;
            } else {
                dp[j][i] = (dp[j-1][i+1] + dp[j-1][i-1]) % MOD;
            }
        }
    }

    long long sum = 0;
    for(int i=0;i<=9;i++){
        sum += dp[a][i];
    }

    cout << sum % MOD << "\n";
    return;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a;
    go();
    return 0;
}