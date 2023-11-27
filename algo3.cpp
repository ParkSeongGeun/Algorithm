#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[101][101];
int dp[101][101];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        dp[0][i] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = 1;
            if(i>1&&j>1){
                if(map[i-1][j-1]==map[i][j]&&map[i-1][j]!=map[i][j]&&map[i][j-1]!=map[i][j]){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
                }
                else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
