#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long res;
int dp[101][10] = {0,1,1,1,1,1,1,1,1,1,0};
int cp_arr[10];

void go(){
    for(int i=1;i<N;i++){
        for(int j=0;j<10;j++){
            if(j==0){
                dp[i][j] = dp[i-1][j+1]%1000000000;
            }
            else if(j==9){
                dp[i][j] = dp[i-1][j-1]%1000000000;
            }
            else
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
        }
    }
}

int main(){
    cin >> N;
    if(N==1){
        cout << 9 << "\n";
        return 0;
    }
    go();
    for(int i=0;i<10;i++){
        res += dp[N-1][i];
    }
    cout << res << "\n";
    return 0;
}