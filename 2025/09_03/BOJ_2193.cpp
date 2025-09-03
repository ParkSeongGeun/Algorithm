#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

ll N;
ll dp[100][2];

void go(int num) {
    // base condition
    dp[1][0] = 0;
    dp[1][1] = 1;

    dp[2][0] = 1;
    dp[2][1] = 0;

    for(int i=3;i<=num;i++){
        dp[i][0] = dp[i-1][0]+dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[num][0] + dp[num][1] << "\n";
    return;
}

int main() {
    cin >> N;
    go(N);
    return 0;
}