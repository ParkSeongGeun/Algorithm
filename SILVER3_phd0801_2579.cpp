#include <iostream>
#include <algorithm>

using namespace std;

int ans, T, N;
int arr[301];
int dp[301];

void go(){
    for(int i = 4;i<=T;i++){
        dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]); 
    }
    ans = dp[T];
}

int main(){
    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    dp[3] = max(arr[1]+arr[3], arr[2]+arr[3]);
    go();
    cout << ans << "\n";
    return 0;
}