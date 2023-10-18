#include <iostream>
#include <algorithm>

using namespace std;

int N, cur;
int arr[1001];
int dp[1001] = {0};

void go(){
    for(int i=0;i<N;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] && dp[j] >= dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    dp[0] = 1;
    go();
    // for(int i=0;i<N;i++){
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";
    sort(dp, dp+N);
    cout << dp[N-1] <<"\n";
    return 0;
}