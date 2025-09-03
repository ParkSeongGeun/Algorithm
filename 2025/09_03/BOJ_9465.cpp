#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int sticker[2][100001];
int dp[100001][3];

int main() {
    int n;
    cin >> n;

    while(n--) {
        int cnt;
        cin >> cnt;

        memset(sticker, 0, sizeof(sticker));
        memset(dp, 0, sizeof(dp));

        for(int i=0;i<2;i++){
            for(int j=0;j<cnt;j++){
                cin >> sticker[i][j];
            }
        }

        dp[0][0] = 0;                    // 0번째 열에서 아무것도 안 선택
        dp[0][1] = sticker[0][0];        // 0번째 열에서 위쪽 선택
        dp[0][2] = sticker[1][0];        // 0번째 열에서 아래쪽 선택

        for(int i=1;i<cnt;i++){
            // i번째 열에서 선택 X
            // 이전 열에서는 어떤 거 선택해도 상관없음
            dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});

            // i번째 열에서 위쪽 선택
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + sticker[0][i];

            // i번째 열에서 아래쪽 선택
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + sticker[1][i];
        }

        int res = max({dp[cnt-1][0], dp[cnt-1][1], dp[cnt-1][2]});
        cout << res << "\n";
    }

    return 0;
}