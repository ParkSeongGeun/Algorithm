#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

typedef unsigned long long ll;

int n;
ll dp[31];

int main() {
    cin >> n;

    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;

    if (n%2!=0) {
        cout << 0 << "\n";
    } else {
        for(int i=6;i<=n;i+=2) {
            dp[i] = dp[i-2] * dp[2];
            for (int j=i-4;j>=0;j-=2) {
                dp[i] += (dp[j] * 2);
            }
        }
        cout << dp[n] << "\n";
    }

    return 0;
}