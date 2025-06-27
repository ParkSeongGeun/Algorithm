#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string x, y;
int res = 0;
int dp[1002][1002];

int main(){
    cin >> x;
    cin >> y;
    for(int i=0;i<x.length();i++){
        for(int j=0;j<y.length();j++){
            if(x[i]==y[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
                res = dp[i+1][j+1] > res ? dp[i+1][j+1] : res;
            }
            else{
                dp[i+1][j+1] = max(dp[i][j], max(dp[i][j+1], dp[i+1][j]));
            }
        }  
    }
    cout << res << "\n";
    return 0;
}