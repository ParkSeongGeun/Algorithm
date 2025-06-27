#include <iostream>
#include <algorithm>

using namespace std;

int n;
int MAP[501][501];
int dp[501][501];
int res;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin >> MAP[i][j];
        }
    }
    dp[1][1] = MAP[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = max(dp[i-1][j]+MAP[i][j], dp[i-1][j-1]+MAP[i][j]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i=1;i<=n;i++){
        if(res<dp[n][i]){
            res = dp[n][i];
        }
    }
    cout << res << "\n";
    return 0;
}