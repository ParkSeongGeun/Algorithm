#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int arr[301];
    int dp[301][2];
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // 초기값 설정
    dp[0][0] = arr[0];    // 0번째 계단을 밟음 (시작점에서 1칸 점프)
    dp[0][1] = 0;         // 불가능하지만 편의상 0
    
    if(n > 1) {
        dp[1][0] = arr[1];           // 1번째 계단을 밟음
        dp[1][1] = arr[0] + arr[1];  // 0번째 → 1번째
    }
    
    for(int i = 2; i < n; i++) {
        // i번째 계단을 밟는데, (i-2)에서 2칸 점프로 온 경우
        // (i-2)는 어떤 방식으로 도달했든 상관 x
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + arr[i];
        
        // i번째 계단을 밟는데, (i-1)에서 1칸 점프로 온 경우  
        // 단, (i-1)은 반드시 2칸 점프로 도달해야 -> 연속 3개 방지
        dp[i][1] = dp[i-1][0] + arr[i];
    }
    
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
    
    return 0;
}