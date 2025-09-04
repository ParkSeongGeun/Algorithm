#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

int n;
int dp[100001];

int main() {
    cin >> n;
    
    fill(dp, dp+100001, INT_MAX);
    dp[0] = 0;

    for(int i=1;i<=n;i++) {
        for(int j=sqrt(i);j>0;j--) {
            if (dp[i] > dp[i-j*j] + 1) {
                dp[i] = dp[i-j*j] + 1;
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}