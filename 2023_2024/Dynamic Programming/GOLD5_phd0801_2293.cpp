#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[11111];
int dp[11111];
int res;

void go(){
    for(int i=1;i<=n;i++){
        for(int j=arr[i];j<=k;j++){
            dp[j] = dp[j] + dp[j-arr[i]];
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    dp[0] = 1;
    go();
    cout << dp[k] << "\n";
    return 0; 
}