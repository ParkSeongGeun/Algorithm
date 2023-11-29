#include <iostream>
#include <algorithm>

using namespace std;

int n;
int res;
int dp[31][31];

int go(int n, int r){
    if(dp[n][r]!=0){
        return dp[n][r];
    }
    if(n==r||r==0){
        return 1;
    }
    else{
        dp[n][r] = go(n-1, r-1) + go(n-1, r);
        return dp[n][r];
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        int first = max(a, b);
        int second = min(a, b);
        cout << go(first, second) << "\n";
    }
    return 0;
}