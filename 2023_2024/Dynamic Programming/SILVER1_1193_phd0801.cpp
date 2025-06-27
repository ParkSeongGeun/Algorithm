#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[3];
int dp[1001][3];
int res;

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            cin >> arr[j];
        }
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[2];
    }
    res = min(dp[N][0], min(dp[N][1], dp[N][2]));
    cout << res << "\n";
    return 0;
}