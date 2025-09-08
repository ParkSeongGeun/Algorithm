#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, k;
ll dp[201][201];

int main() {
    cin >> n >> k;

    for(int i=0;i<=200;i++){
        for(int j=0;j<=200;j++){
            if(j==0) {
                if (i==0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            } else if (j==1 && i <= n){
                dp[i][j] = 1;
            }
        }
    }

    for(int j=2;j<=k;j++){
        for(int i=0;i<=n;i++){
            // dp[i]j] = dp[0][j-1] + dp[1][j-1] +... + dp[i][j-1];
            for(int z=0;z<=i;z++){
                dp[i][j] = (dp[i][j] + dp[z][j-1]) % 1000000000;
            }
        }
    }

    cout << dp[n][k] % 1000000000 << "\n";
    return 0;
}