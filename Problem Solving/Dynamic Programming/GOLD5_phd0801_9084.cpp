#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M;
int arr[21];
int dp[10001];

void go(){
    for(int i=1;i<=N;i++){
        for(int j=arr[i]; j <= M; j++){
            dp[j] = dp[j] + dp[j-arr[i]];
        }
        // for(int q=1;q<=M;q++){
        //     cout << dp[q] << " ";
        // }
        // cout << "\n";
    }
}

int main(){
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> N;
        // 초기화
        for(int k=0; k<= 20; k++){
            arr[k] = 0;
        }
        for(int k=0; k<=10000; k++){
            dp[k] = 0;
        }
        for(int j=1;j<=N;j++){
            cin >> arr[j];
        }
        cin >> M;
        dp[0] = 1;
        go();
        cout << dp[M] << "\n";
    }
    return 0;
}