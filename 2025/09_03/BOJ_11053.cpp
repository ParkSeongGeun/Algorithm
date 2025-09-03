#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int arr[1001];
int dp[1001];

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        dp[i] = 1;  // 최소 길이는 1 (자기 혼자)
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // for(int i=0;i<N;i++){
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";

    int result = 0;
    for(int i = 0; i < N; i++) {
        result = max(result, dp[i]);
    }
    cout << result << "\n";

    return 0;
}