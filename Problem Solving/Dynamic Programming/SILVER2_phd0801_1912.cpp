#include <iostream>
#include <algorithm>

using namespace std;

int n;
int res;
int arr[100001];
int dp[100001];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    dp[0] = arr[0];
    res = dp[0];
    for(int i=1;i<n;i++){
        dp[i] = max(dp[i-1]+arr[i], arr[i]);
        res = dp[i] > res ? dp[i] : res;
    }
    cout << res << "\n";
    return 0;
}