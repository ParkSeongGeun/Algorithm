#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int dp[10001];
int v[101];

void go(){
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=k;j++){
            dp[j] = min(dp[j], dp[j-v[i]] + 1);
        }
        for(int q = 1; q <= k; q++){
            cout << dp[q] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n >> k;
    int input_num;
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=k;i++){
        dp[i] = 99999;
    }
    
    go();

    if(dp[k] == 99999){
        cout << "-1" << "\n";
    }
    else{
        cout << dp[k] << "\n";
    }
    return 0;
}