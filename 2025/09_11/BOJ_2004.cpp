#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

int n, r;

vector<pair<int, int>> v(3);

void checkTwoFive(int n, int param) {
    
    ll cnt1 = 2;
    ll cnt2 = 5;

    while(1) {
        int temp = n / cnt1;
        if (temp == 0) {
            break;
        }

        if (temp > 0) {
            v[param].first += temp;
        }
        cnt1 *= 2;
    }

    while(1) {
        int temp = n / cnt2;
        if (temp == 0) {
            break;
        }

        if (temp > 0) {
            v[param].second += temp;
        }
        cnt2 *= 5;
    }
}

int main() {
    cin >> n >> r;

    checkTwoFive(n, 0);
    checkTwoFive(r, 1);
    checkTwoFive(n-r, 2);

    // for(int i=0;i<3;i++){
    //     cout << v[i].first << ", " << v[i].second << "\n";
    // }

    int two_count = v[0].first - v[1].first - v[2].first;
    int five_count = v[0].second - v[1].second - v[2].second;

    int result = min(two_count, five_count);

    cout << result << "\n";
    return 0;
}