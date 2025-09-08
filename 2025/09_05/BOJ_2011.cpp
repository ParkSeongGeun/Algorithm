#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;

int input[5001];
ll dp[5001];

int main() {
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        input[i] = s[i] - '0';
    }

    if (input[0] == 0){
        cout << 0 << "\n";
        return 0;
    }

    dp[0] = 1;
    if (s.length() >= 2) {
        if (0 <= input[0] * 10 + input[1] && input[0] * 10 + input[1] <= 26) {
            if (input[1] == 0) {
            dp[1] = 1;
            } else {
                dp[1] = 2;
            }
        } else {
            if (s.length() >= 1 && input[1] == 0) {
                cout << 0 << "\n";
                return 0;
            }
            dp[1] = 1;
        }
    }
    
    for(int i=2;i<s.length();i++){
        // condition
        if (0 <= input[i] + 10 * input[i-1] && input[i] + 10 * input[i-1] <= 26) 
        {
            if (input[i] == 0) {
                if (input[i-1] == 0) {
                    cout << 0 << "\n";
                    return 0;
                }
                dp[i] = dp[i-2] % 1000000;
            } else {
                if(input[i-1] != 0) {
                    dp[i] = (dp[i-2] + dp[i-1]) % 1000000;
                } else {
                    dp[i] = dp[i-1] % 1000000;
                }
            }
        }
        else
        {
            if (input[i] == 0) {
                cout << 0 << "\n";
                return 0;
            }
            dp[i] = dp[i-1] % 1000000;
        }
    }

    // for(int i=0;i<s.length();i++){
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";

    cout << dp[s.length()-1] % 1000000 << "\n";
    return 0;
}