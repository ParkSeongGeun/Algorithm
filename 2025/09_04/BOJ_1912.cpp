#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int n;
int arr[100001];
int dp[100001];

int main() {
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    dp[0] = arr[0];

    for(int i=1;i<n;i++){
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
    }

    int res = INT_MIN;

    for(int i=0;i<n;i++){
        if (res < dp[i]) {
            res = dp[i];
        }
    }

    cout << res << "\n";
    return 0;
}