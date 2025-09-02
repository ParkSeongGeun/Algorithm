// BOJ 1182: 부분수열의 합
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        if (sum == s) ans++;
    }
    
    cout << ans << "\n";
    return 0;
}