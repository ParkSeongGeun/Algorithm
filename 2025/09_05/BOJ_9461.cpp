#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

int n;
ll dp[101];

int main() {
    cin >> n;

    // base condition
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;
    dp[9] = 7;
    dp[10] = 9;
     
    // dp
    for(int i=11;i<=100;i++){
        dp[i] = dp[i-5] + dp[i-1];
    }

    int cnt;
    for(int i=0;i<n;i++){
        cin >> cnt;
        cout << dp[cnt] << "\n";
    }

    return 0;
}