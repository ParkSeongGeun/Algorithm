#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    unordered_map<ll, ll> dict;

    ll cnt;

    for(int i=0;i<n;i++){
        cin >> cnt;
        dict[cnt]++; 
    }

    pair<ll, ll> res;

    res.first = INT_MIN;
    res.second = 0;

    for(auto& pair : dict) {
        if (res.first < pair.second) {
            res.first = pair.second;
            res.second = pair.first;
        } else if (res.first == pair.second) {
            if (res.second > pair.first) {
                res.second = pair.first;
            }
        }
    }

    cout << res.second << "\n";
    return 0;
}